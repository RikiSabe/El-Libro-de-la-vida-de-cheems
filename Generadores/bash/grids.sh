# [n,m]
filas=$1
columnas=$2

for ((i = 1; i <= filas; i++)); do
  for ((j = 1; j <= columnas; j++)); do
    if (( RANDOM % 2 )); then
      echo -n "."
    else
      echo -n "#"
    fi
  done
  echo #endl
done
