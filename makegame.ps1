$tracks = 'assets\tilemaped\tracks\final'
$globale:tilessize = ''

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

$globale:tilessize = $globale:tilessize + " " + $(get_tls -Tiles $curpath)

}

Get-ChildItem -Path "$tracks" | Foreach-Object { make_track -Track $_.Name }

Write-Output $globale:tilessize

$curfile = "tools\gameaddr.exe"

Invoke-Expression "$curfile $globale:tilessize"

$curfile = "tools\game.bin"
$curpath = "DAT\GAME"

Copy-Item -Path $curfile -Destination $curpath
