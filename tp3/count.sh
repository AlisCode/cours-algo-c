sort test | uniq > test_names
cat test_names | while read line
do NB=$(grep -o $line test | wc -w)
echo ${line} : $NB
done
rm test_names
