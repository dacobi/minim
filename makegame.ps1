$tracks = 'assets\tilemaped\tracks\final'
$tilessize = ''

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

$tilessize = $tilessize + " " + $(get_tls -Tiles $curpath)

Write-Output $tilessize

}

make_track -Track "t1"
