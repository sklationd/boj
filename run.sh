if [ $1 ];then
mkdir $1 
cd $1
cp ../sample.cpp $1.cpp
code $1.cpp
else 
echo "Usage: ./run.sh <number>"
fi