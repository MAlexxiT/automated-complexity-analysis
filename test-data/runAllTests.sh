#chmod +x runAllTests.sh
for FILE in *; do 
    extension="${FILE##*.}"
    #echo $extension;
    if [[ $FILE == *.cpp ]]
    then
        line=$(head -n 1 $FILE)
        echo "----------------------------";
        echo $FILE;
        ./analizadors<$FILE
        echo " ";
        echo $line;
        
    fi
done
