if [ $1 ];then
mkdir src/$1 
cd src/$1
cp ../../sample.cpp $1.cpp
code $1.cpp
else 
echo "Usage: ./run.sh <number>"
fi
