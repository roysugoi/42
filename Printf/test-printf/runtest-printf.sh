GREEN='\033[0;32m'
DARK_BLUE='\e[1;34m'
RED='\x1B[31m'
BLUE='\e[96m'
NC='\033[0m'
i=0
success=0
error=0

# $1 = text, $2 = test number
test()
{
	printf "$1" >> test-printf/result.log
	test-printf/test.out $2 > test-printf/original_output
	echo $? >> test-printf/original_output
	sh test-printf/timeout.sh 1 test-printf/test.out $2 user > test-printf/user_output 2> /dev/null
	ret=$(echo $?)
	echo $ret >> test-printf/user_output
	if diff "test-printf/original_output" "test-printf/user_output" >> /dev/null
	then
		if [ $error -eq 1 ]
		then
			printf "\n"
		fi
    	printf "${GREEN}OK ${NC}"
    	printf "${GREEN}OK ${NC}\n" >> test-printf/result.log
		((success++))
		error=0
	else
    	printf "\n${RED}$1"
		if [ $ret -eq 142 ] #timeout
		then
			printf "${RED}TIMEOUT${NC}"
			printf "${RED}TIMEOUT${NC}\n" >> test-printf/result.log
		else
			printf "${RED}FAILED${NC}"
			printf "${RED}FAILED${NC}\n" >> test-printf/result.log
		fi
		error=1
	fi
	((i++))
}

rm test-printf/result.log
make all
make bonus
gcc -Wall -Wextra -Werror -Wformat=0 test-printf/test-main.c libftprintf.a -o test-printf/test.out
printf "\n${BLUE}[E - Tests with .]${NC}\n"
test "$i - (\"%%.0%%\") : ${NC}" $i 
test "$i - (\"%%.0%%\") : ${NC}" $i 
test "$i - (\"%%.1%%\") : ${NC}" $i 
test "$i - (\"%%.2%%\") : ${NC}" $i 
test "$i - (\"%%.10%%\") : ${NC}" $i 
test "$i - (\"%%.0s\", \"\") : ${NC}" $i 
test "$i - (\"%%.1s\", \"\") : ${NC}" $i 
test "$i - (\"%%.3s\", \"\") : ${NC}" $i 
test "$i - (\"%%.0s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%.1s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%.2s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%.5s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%.6s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%.7s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%.s\", 42) : ${NC}" $i 
test "$i - (\"%%.0d\", 0) : ${NC}" $i 
test "$i - (\"%%.1d\", 0) : ${NC}" $i 
test "$i - (\"%%.2d\", 0) : ${NC}" $i 
test "$i - (\"%%.0d\", 5) : ${NC}" $i 
test "$i - (\"%%.1d\", 5) : ${NC}" $i 
test "$i - (\"%%.2d\", 5) : ${NC}" $i 
test "$i - (\"%%.0d\", 42) : ${NC}" $i 
test "$i - (\"%%.1d\", 42) : ${NC}" $i 
test "$i - (\"%%.2d\", 42) : ${NC}" $i 
test "$i - (\"%%.3d\", 42) : ${NC}" $i 
test "$i - (\"%%.10d\", 42) : ${NC}" $i 
test "$i - (\"%%.6d\", 100) : ${NC}" $i 
test "$i - (\"%%.0d\", -1) : ${NC}" $i 
test "$i - (\"%%.1d\", -1) : ${NC}" $i 
test "$i - (\"%%.2d\", -1) : ${NC}" $i 
test "$i - (\"%%.3d\", -1) : ${NC}" $i 
test "$i - (\"%%.0d\", -42) : ${NC}" $i 
test "$i - (\"%%.1d\", -42) : ${NC}" $i 
test "$i - (\"%%.3d\", -42) : ${NC}" $i 
test "$i - (\"%%.4d\", -42) : ${NC}" $i 
test "$i - (\"%%.20d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%.20d\", INT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%.20d\", INT_MIN) : ${NC}" $i 
test "$i - (\"%%.20d\", INT_MIN - 1) : ${NC}" $i 
test "$i - (\"%%.0i\", 0) : ${NC}" $i 
test "$i - (\"%%.1i\", 0) : ${NC}" $i 
test "$i - (\"%%.2i\", 0) : ${NC}" $i 
test "$i - (\"%%.0i\", 5) : ${NC}" $i 
test "$i - (\"%%.1i\", 5) : ${NC}" $i 
test "$i - (\"%%.2i\", 5) : ${NC}" $i 
test "$i - (\"%%.0i\", 42) : ${NC}" $i 
test "$i - (\"%%.1i\", 42) : ${NC}" $i 
test "$i - (\"%%.2i\", 42) : ${NC}" $i 
test "$i - (\"%%.3i\", 42) : ${NC}" $i 
test "$i - (\"%%.10i\", 42) : ${NC}" $i 
test "$i - (\"%%.6i\", 100) : ${NC}" $i 
test "$i - (\"%%.0i\", -1) : ${NC}" $i 
test "$i - (\"%%.1i\", -1) : ${NC}" $i 
test "$i - (\"%%.2i\", -1) : ${NC}" $i 
test "$i - (\"%%.3i\", -1) : ${NC}" $i 
test "$i - (\"%%.0i\", -42) : ${NC}" $i 
test "$i - (\"%%.1i\", -42) : ${NC}" $i 
test "$i - (\"%%.3i\", -42) : ${NC}" $i 
test "$i - (\"%%.4i\", -42) : ${NC}" $i 
test "$i - (\"%%.20i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%.20i\", INT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%.20i\", INT_MIN) : ${NC}" $i 
test "$i - (\"%%.20i\", INT_MIN - 1) : ${NC}" $i 
test "$i - (\"%%.0u\", 0) : ${NC}" $i 
test "$i - (\"%%.1u\", 0) : ${NC}" $i 
test "$i - (\"%%.2u\", 0) : ${NC}" $i 
test "$i - (\"%%.0u\", 5) : ${NC}" $i 
test "$i - (\"%%.1u\", 5) : ${NC}" $i 
test "$i - (\"%%.2u\", 5) : ${NC}" $i 
test "$i - (\"%%.0u\", 42) : ${NC}" $i 
test "$i - (\"%%.1u\", 42) : ${NC}" $i 
test "$i - (\"%%.2u\", 42) : ${NC}" $i 
test "$i - (\"%%.3u\", 42) : ${NC}" $i 
test "$i - (\"%%.10u\", 42) : ${NC}" $i 
test "$i - (\"%%.6u\", 100) : ${NC}" $i 
test "$i - (\"%%.0u\", -1) : ${NC}" $i 
test "$i - (\"%%.1u\", -1) : ${NC}" $i 
test "$i - (\"%%.2u\", -1) : ${NC}" $i 
test "$i - (\"%%.3u\", -1) : ${NC}" $i 
test "$i - (\"%%.0u\", -42) : ${NC}" $i 
test "$i - (\"%%.1u\", -42) : ${NC}" $i 
test "$i - (\"%%.3u\", -42) : ${NC}" $i 
test "$i - (\"%%.4u\", -42) : ${NC}" $i 
test "$i - (\"%%.20u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%.20u\", UINT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%.0x\", 0) : ${NC}" $i 
test "$i - (\"%%.1x\", 0) : ${NC}" $i 
test "$i - (\"%%.2x\", 0) : ${NC}" $i 
test "$i - (\"%%.0x\", 5) : ${NC}" $i 
test "$i - (\"%%.1x\", 5) : ${NC}" $i 
test "$i - (\"%%.2x\", 5) : ${NC}" $i 
test "$i - (\"%%.0x\", 42) : ${NC}" $i 
test "$i - (\"%%.1x\", 42) : ${NC}" $i 
test "$i - (\"%%.2x\", 42) : ${NC}" $i 
test "$i - (\"%%.3x\", 42) : ${NC}" $i 
test "$i - (\"%%.10x\", 42) : ${NC}" $i 
test "$i - (\"%%.6x\", 100) : ${NC}" $i 
test "$i - (\"%%.0x\", -1) : ${NC}" $i 
test "$i - (\"%%.1x\", -1) : ${NC}" $i 
test "$i - (\"%%.2x\", -1) : ${NC}" $i 
test "$i - (\"%%.3x\", -1) : ${NC}" $i 
test "$i - (\"%%.0x\", -42) : ${NC}" $i 
test "$i - (\"%%.1x\", -42) : ${NC}" $i 
test "$i - (\"%%.3x\", -42) : ${NC}" $i 
test "$i - (\"%%.4x\", -42) : ${NC}" $i 
test "$i - (\"%%.20x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%.20x\", UINT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%.0X\", 0) : ${NC}" $i 
test "$i - (\"%%.1X\", 0) : ${NC}" $i 
test "$i - (\"%%.2X\", 0) : ${NC}" $i 
test "$i - (\"%%.0X\", 5) : ${NC}" $i 
test "$i - (\"%%.1X\", 5) : ${NC}" $i 
test "$i - (\"%%.2X\", 5) : ${NC}" $i 
test "$i - (\"%%.0X\", 42) : ${NC}" $i 
test "$i - (\"%%.1X\", 42) : ${NC}" $i 
test "$i - (\"%%.2X\", 42) : ${NC}" $i 
test "$i - (\"%%.3X\", 42) : ${NC}" $i 
test "$i - (\"%%.10X\", 42) : ${NC}" $i 
test "$i - (\"%%.6X\", 100) : ${NC}" $i 
test "$i - (\"%%.0X\", -1) : ${NC}" $i 
test "$i - (\"%%.1X\", -1) : ${NC}" $i 
test "$i - (\"%%.2X\", -1) : ${NC}" $i 
test "$i - (\"%%.3X\", -1) : ${NC}" $i 
test "$i - (\"%%.0X\", -42) : ${NC}" $i 
test "$i - (\"%%.1X\", -42) : ${NC}" $i 
test "$i - (\"%%.3X\", -42) : ${NC}" $i 
test "$i - (\"%%.4X\", -42) : ${NC}" $i 
test "$i - (\"%%.20X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%.20X\", UINT_MAX + 1) : ${NC}" $i 
printf "\n\n${DARK_BLUE}Result [$success/$i]${NC}"
