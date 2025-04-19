# g++ -Werror -g 2105118.cpp -o 2105118
# valgrind -s --leak-check=full ./2105118

# g++ -fsanitize=address -g 2105118.cpp -o 2105118
# g++ 2105118.cpp -o 2105118
# ./2105118 1 sample_input.txt out.txt

g++ -fsanitize=address -g 2105118_report_generator.cpp -o 2105118_report
./2105118_report sample_input.txt
rm garbage.txt
rm 2105118_report