# rm -rf diffd
# mkdir diffd
# for i in {1..5}; do
#     ./run-script.sh sample_io/input${i}.txt
#     diff -wb sample_io/log${i}.txt output/parserLog.txt > diffd/diff${i}.txt
# done

./run-script.sh sample_io/input4.txt
diff -wb output/parserLog.txt sample_io/log4.txt > diff.txt