@echo off
cd ..
"C:\Program Files (x86)\MSBuild\12.0\Bin\MSBuild.exe" /p:Configuration=Release
cd Installer

Packer\upx.exe ..\bin\Release\KcaseCrypto.dll
Packer\upx.exe ..\bin\Release\KcaseCms.dll
Packer\upx.exe ..\bin\Release\KcaseCert.dll
Packer\upx.exe ..\bin\Release\KCaseLib.exe
Packer\upx.exe ..\bin\Release\KCaseAgent.exe
Packer\upx.exe ..\bin\Release\KCaseManager.exe

"C:\Program Files (x86)\NSIS\makensis.exe" KCaseAgent_Installer.nsi
timeout 1 > NUL
cd CodeSignning
codesign_setup.bat