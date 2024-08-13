# [n,m] - [a,b]
filas=$1
columnas=$2
for ((i = 1; i <= filas; i++)); do
  seq $3 $4 | shuf -n $columnas | tr '\n' ' '
  echo
done
