$tracks = 'assets\tilemaped\tracks\final'
$tilessize = ''

function make_track{
param([String]$Track)

$folder = $tracks + "\" + $track
$tracknum = $track[-1]

$curpath = "DAT\TLST" + $tracknum
$curfile = $folder + "\tiles.bin"

Copy-Item -Path $curfile -Destination $curpath

}

make_track -Track "t2"
