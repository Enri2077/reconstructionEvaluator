echo $1 $2

cp "kitti_stereo.config" "kitti"$1"_stereo.config"
sed -i -- "s/€1/"$1"/g" "kitti"$1"_stereo.config"
sed -i -- "s/€2/"$2"/g" "kitti"$1"_stereo.config"


