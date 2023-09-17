$tracks = 'assets\tilemaped\tracks\final'
$tilessize = ''

function make_track{
param([String]$Track)

$folder = $tracks + "\" + $track
$tracknum = $track[-1]

Copy-Item -Path $folder+"\tiles.bin" -Destination "DAT\TLST"+$tracknum

}

make_track -Track "t2"
