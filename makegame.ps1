$tracks = 'assets\tilemaped\tracks\final'
$global:tilessize = ''

function get_tls{
param([String]$Tiles)
	
	return (Get-Item -Path $tiles).Length
}

function make_track{
param([String]$Track)

$folder = $tracks + "\" + $track
$tracknum = $track[-1]

$curfile = $folder + "\tiles.bin"
$curpath = "DAT\TLST" + $tracknum

Copy-Item -Path $curfile -Destination $curpath

$curfile = $folder + "\map0.bin"
$curpath = "DAT\TRK" + $tracknum

Copy-Item -Path $curfile -Destination $curpath

$curfile = $folder + "\colmap0.bin"
$curpath = "DAT\CLM" + $tracknum

Copy-Item -Path $curfile -Destination $curpath

$curfile = $folder + "\pal.bin"
$curpath = "DAT\PAL" + $tracknum

Copy-Item -Path $curfile -Destination $curpath

$curpath = "tools\waypoint.t" + $tracknum
$curfile = "tools\waypoints.exe"

Invoke-Expression "$curfile $curpath"

$curfile = "tools\waypoint.t" + $tracknum + ".bin"
$curpath = "DAT\WAY" + $tracknum

Copy-Item -Path $curfile -Destination $curpath

$curpath = "DAT\TLST" + $tracknum

$global:tilessize = $global:tilessize + " " + $(get_tls -Tiles $curpath)

}

Get-ChildItem -Path "$tracks" | Foreach-Object { make_track -Track $_.Name }

Write-Output $global:tilessize

$curfile = "tools\gameaddr.exe"

Invoke-Expression "$curfile $global:tilessize"

$curfile = "game.bin"
$curpath = "DAT\GAME"

Copy-Item -Path $curfile -Destination $curpath

Remove-Item -Path $curfile
