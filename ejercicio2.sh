#!/bin/bash
# 1. Pedir el nombre
echo "Bienvenido"
read -p "Ingrese el nombre del archivo: " filename
# 2. Verificación
# 2a. Si está vacío o ya existe el nombre, salir del programa
if [[ -z "$filename" ]] || [[ -e "${filename}.c" ]]
then
  exit
# 2b. En caso contrario, crear el archivo *.c
else
  touch "${filename}.c"
  echo "/* " >> ${filename}.c
  echo "Autor: ${USER}" >> ${filename}.c
  echo "Compilador: gcc, version $(gcc --version | grep gcc | awk '{print $4}')" >> ${filename}.c
  echo "Compilado: gcc ${filename}.c -o ${filename}" >> ${filename}.c
  echo "Fecha: $(date)" >> ${filename}.c
  read -p "¿Qué librería desea agregar? " library
  echo "Librerías: ${library}" >> ${filename}.c
  read -p "Ingrese el resumen del documento (una línea): " summary
  echo "Resumen: ${summary}" >> ${filename}.c
  read -p "¿Cuáles son las entradas? " input
  echo "Entradas: ${input}" >> ${filename}.c
  read -p "¿Cuáles son las salidas? " output
  echo "Salidas: ${output}" >> ${filename}.c
  echo "*/" >> ${filename}.c
  echo "// Librerías" >> ${filename}.c
  echo "#include <${library}.h>" >> ${filename}.c
  echo "// Numerar los pasos del pseudocódigo" >> ${filename}.c
fi
