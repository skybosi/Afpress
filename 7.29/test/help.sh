cp picture.txt tmp
cat tmp|tr "7" "\n"  > tmp2
cat tmp2 | grep -v "^$" > tmp3
#cat tmp3 | wc -l
cat tmp3 | sort -n | awk '{if($1 <= 9) print $0}' | wc -l
cat tmp3 | sort -n | awk '{if($1 >= 10 && $1 < 100) print $0}' | wc -l
cat tmp3 | sort -n | awk '{if($1 >= 100 && $1 < 1000) print $0}' | wc -l
cat tmp3 | sort -n | awk '{if($1 >= 1000 && $1 < 10000) print $0}' | wc -l
cat tmp3 | sort -n | awk '{if($1 >= 10000 && $1 < 100000) print $0}' | wc -l
cat tmp3 | sort -n | awk '{if($1 >= 100000 && $1 < 1000000) print $0}' | wc -l
rm tmp*
