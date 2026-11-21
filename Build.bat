@echo off
setlocal
set "SOURCE=%~dp0"
set "OUT=bin"
set "RelBuild=Release"
if not exist "%SOURCE%%OUT%\temp" mkdir "%SOURCE%%OUT%\temp"
if errorlevel 1 exit /b 1
set "TEMP=%SOURCE%%OUT%\temp"
set "TMP=%TEMP%"
rem assume the 18362 EWDK is mounted at H:
call "H:\BuildEnv\SetupBuildEnv.cmd" x86_arm64
@echo off
if errorlevel 1 exit /b 1

cd /d "%SOURCE%"
if errorlevel 1 exit /b 1

if not exist "%OUT%\package" mkdir "%OUT%\package"
if errorlevel 1 exit /b 1
if not exist "%OUT%\package\PDB" mkdir "%OUT%\package\PDB"
if errorlevel 1 exit /b 1

msbuild.exe AP6256\ap6256.vcxproj /t:Rebuild /m /nologo /v:minimal ^
 /p:Configuration=%RelBuild% /p:Platform=ARM64 ^
 /p:WindowsTargetPlatformVersion=10.0.18362.0 ^
 /p:SignMode=Off /p:EnableInf2cat=false /p:SupportsPackaging=false ^
 /p:RunCodeAnalysis=false /p:Driver_SpectreMitigation=false ^
 /p:Ap6256BuildVersion=1.0.0.0
if errorlevel 1 exit /b 1

msbuild.exe AP6256FN\ap6256fn.vcxproj /t:Rebuild /m /nologo /v:minimal ^
 /p:Configuration=%RelBuild% /p:Platform=ARM64 ^
 /p:WindowsTargetPlatformVersion=10.0.18362.0 ^
 /p:SignMode=Off /p:EnableInf2cat=false /p:SupportsPackaging=false ^
 /p:RunCodeAnalysis=false /p:Driver_SpectreMitigation=false ^
 /p:Ap6256BuildVersion=1.0.0.0
if errorlevel 1 exit /b 1

msbuild.exe AP6256BT\ap6256bt.vcxproj /t:Rebuild /m /nologo /v:minimal ^
 /p:Configuration=%RelBuild% /p:Platform=ARM64 ^
 /p:WindowsTargetPlatformVersion=10.0.18362.0 ^
 /p:SignMode=Off /p:EnableInf2cat=false /p:SupportsPackaging=false ^
 /p:RunCodeAnalysis=false /p:Driver_SpectreMitigation=false ^
 /p:Ap6256BuildVersion=1.0.0.0
if errorlevel 1 exit /b 1

for %%F in (
    AP6256\ARM64\%RelBuild%\ap6256.sys
    AP6256FN\ARM64\%RelBuild%\ap6256fn.sys
    AP6256BT\ARM64\%RelBuild%\ap6256bt.sys
    AP6256\ARM64\%RelBuild%\ap6256.inf
    AP6256FN\ARM64\%RelBuild%\ap6256fn.inf
    AP6256BT\ARM64\%RelBuild%\ap6256bt.inf
    Firmware\BCM4345C5.hcd
    Firmware\4345r6nvram.txt
    Firmware\4345r6rtecdc.bin
    Firmware\4345r9.clmb
    Firmware\4345r9nvram.txt
    Firmware\4345r9rtecdc.bin
) do (
    if exist "%SOURCE%%%F" (
        copy /y "%SOURCE%%%F" "%OUT%\package\" >nul
        if errorlevel 1 exit /b 1
    ) else (
        echo !!! MISSING: %SOURCE%%%F
        exit /b 1
    )
)

for %%F in (
    AP6256\ARM64\%RelBuild%\ap6256.pdb
    AP6256FN\ARM64\%RelBuild%\ap6256fn.pdb
    AP6256BT\ARM64\%RelBuild%\ap6256bt.pdb
) do (
    if exist "%SOURCE%%%F" (
        copy /y "%SOURCE%%%F" "%OUT%\package\PDB\" >nul
        if errorlevel 1 exit /b 1
    ) else (
        echo !!! MISSING: %SOURCE%%%F
        exit /b 1
    )
)

echo Built package: "%OUT%\package"
exit /b 0
