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

# generator de archives a.cpp to N.cpp
for((i = 1; i <= $1 ; i++))
do
    letra=$(printf \\$(printf '%03o' $(($i+97))))
    # Create copy template
    cp template.cpp "${letra}.cpp"
    # Remove in error case
    # rm "${letra}.cpp"
done
echo "archivos creados"
#RUN
./script.sh 11

