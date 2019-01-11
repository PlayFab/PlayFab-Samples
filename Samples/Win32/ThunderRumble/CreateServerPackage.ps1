Param(
  [string]$buildConfig
)

echo "Packaging server build for config: $buildConfig"

$orig_workingdir = Get-Location;
$timestamp = [int][double]::Parse((Get-Date -UFormat %s));
$out_path = "$orig_workingdir/ServerPackage_" + $buildConfig + "_$timestamp.zip";

if (Test-Path $out_path) 
{
  Remove-Item $out_path
}

Set-Location -Path "x64/$buildConfig"
Compress-Archive -LiteralPath "external_tools\remotedebugger.zip",
"Bootstrapper.exe",
"Bootstrapper.exe.config",
"config.json",
"GSDK_CPP_CSharpWrapper.dll",
"libcrypto-1_1-x64.dll",
"libcurl.dll",
"libssl-1_1-x64.dll",
"libssh2.dll",
"Microsoft.Playfab.Gaming.GSDK.CSharp.dll",
"Newtonsoft.Json.dll",
"Newtonsoft.Json.xml",
"PlayFabAllSDK.dll",
"ThunderRumbleServer.exe",
"zlib1.dll" -CompressionLevel Optimal -DestinationPath $out_path

Set-Location -Path $orig_workingdir