$GBDKbin= "..\..\..\bin"
$GameName="WorldEater"

function SpitName {
    echo $input.FullName
}
function Compile {
    if(!(Test-Path -Path "obj" )){
        New-Item -ItemType directory -Path "obj"
    }
    $input | ForEach-Object {
        $oname = $_.Name.SubString(0,$_.Name.LastIndexOf('.')) + ".o"
        $cname = $_.FullName
        Invoke-Expression "$GBDKbin\lcc    -c -o obj\$oname ""$cname"""
    }
}
function Link {
    $objs = $input -join " "
    Invoke-Expression "$GBDKbin\lcc    -o obj\$GameName.gb $objs"
}

Get-ChildItem -Recurse -Filter "*.c" | SpitName
Get-ChildItem -Recurse -Filter "*.c" | Compile
Get-ChildItem "obj" -Filter "*.o" | ForEach-Object{$_.FullName}| Link 