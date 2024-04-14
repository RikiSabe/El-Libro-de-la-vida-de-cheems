#script run for cheems app cpp to fast
#g++ version standard
g++ $1.cpp -o main
./main
rm main
#g++ personality
g++ -std=c++17 $1.cpp -o main
./main
rm main
#python standard
#windows
py $1.py
#GNULinux
python3 $1.py

#example console
#Autorization
chmod +x script.sh
#RUN
./script.sh main
#main = main.cpp "without extension .cpp"
