/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, Nov 21, 2021
Time of Last Modification: 9:16am EST, Friday, Nov 19, 2021
Description: Hashing
*/
#include <iostream>
using namespace std;

unsigned Hash1( const string & key, const int h_size );
unsigned Hash2( const string & key, const int h_size );
int main() {
	cout << "Results of Hash1 when h_size is 64:" << endl;
	cout << Hash1("hello", 64) << endl;
	cout << Hash1("world", 64) << endl;
	cout << Hash1("you", 64) << endl;
	cout << Hash1("me", 64) << endl;
	cout << Hash1("his", 64) << endl;
	cout << Hash1("her", 64) << endl;
	cout << Hash1("asdas", 64) << endl;
	cout << Hash1("rguehg", 64) << endl;
	/* Part b:
	This is not a good has function when size is 64. There are many collisions at 48 and 16. The below code shows the function operates much better when h_size is a prime number 67 instead (less collisions). Additionally, because the original hash1 function uses an even multiplier (16), and when the modulo operator is applied to the sum, the posibility for collisions is much higher.
	*/
	cout << "Results of Hash1 when h_size is 67:" << endl;
	cout << Hash1("hello", 67) << endl;
	cout << Hash1("world", 67) << endl;
	cout << Hash1("you", 67) << endl;
	cout << Hash1("me", 67) << endl;
	cout << Hash1("his", 67) << endl;
	cout << Hash1("her", 67) << endl;
	cout << Hash1("asdas", 67) << endl;
	cout << Hash1("rguehg", 67) << endl;
	cout << "Results of Hash2 when h_size is 64:" << endl;
	cout << Hash2("hello", 64) << endl;
	cout << Hash2("world", 64) << endl;
	cout << Hash2("you", 64) << endl;
	cout << Hash2("me", 64) << endl;
	cout << Hash2("his", 64) << endl;
	cout << Hash2("her", 64) << endl;
	cout << Hash2("asdas", 64) << endl;
	cout << Hash2("rguehg", 64) << endl;
	cout << "Results of Hash2 when h_size is 71:" << endl;
	cout << Hash2("hello", 71) << endl;
	cout << Hash2("world", 71) << endl;
	cout << Hash2("you", 71) << endl;
	cout << Hash2("me", 71) << endl;
	cout << Hash2("his", 71) << endl;
	cout << Hash2("her", 71) << endl;
	cout << Hash2("asdas", 71) << endl;
	cout << Hash2("rguehg", 71) << endl;
} 

unsigned Hash1( const string & key, const int h_size ){
	unsigned int value = 0;
	for (int i=0; i<key.length(); i++){
		value = (value+ key[i])*16;
	}
	return value % h_size;
}
unsigned Hash2( const string & key, const int h_size ){
	unsigned int value = 0;
	for (int i=0; i<key.length(); i++){
		value = value*31 + key[i];
	}
	return value % h_size;
}
/* 
Part a:
	example using "hello"
	value = (0 + 72) * 16 = 1152
	value = (1152 + 101) * 16 = 20,048
	value = (20,048 + 108) * 16 = 322496
	value = (322496 + 108) * 16 = 5161664
	value = (5,161,664 + 111) * 16 = 82,588,400
	value = ((((((72(16)(16)(16)(16)(16)) + 101(16)(16)(16)(16))  + 108(16)(16)(16))  + 108(16)(16)) + 111(16)) = 82,588,400
	value = (∑ key[i]*16^(key.length-i)) % h_size (from i=0 to i=key.length-1)
Part c:
	example using "you"
	value = (0 * 31) + 121 = 121
	value = (121 * 31) + 110 = 3861
	value = (3861 * 31) + 117 = 119808
	value = 121(31)(31) + 110(31) + 117 = 119808
	value = (∑ key[i]*31^(key.length-(i+1))) % h_size (from i=0 to i=key.length-1)
Part d:
	Determining which hash function is better is determined by the number of collisions that occur. Hash2 is a much better hash function because it utilizes an odd multiplier. It functions best with an odd h_size as well (as seen in Hash2 when h_size is 71) where in my tests there were 0 collisions. Regarding Hash2 with an even h_size -- there were 3 collisions.

	Here are the results of the hash functions performance:
	Hash1 w/ even h_size: 6 collisions
	Hash1 w/ odd h_size: 4 collisions
	Hash2 w/ even h_size: 3 collisions
	Hash2 w/ odd h_size: 0 collisions

	From this we can discern that having an odd multiplier within the for-loop combined with an odd modulo operand will result in the least number of colissions.

Sample Output:
Results of Hash1 when h_size is 64:
48
0
16
16
48
32
48
48
Results of Hash1 when h_size is 67:
7
40
21
40
42
7
22
53
Results of Hash2 when h_size is 64:
18
18
31
24
18
21
36
4
Results of Hash2 when h_size is 71:
30
33
62
1
9
26
22
38

*/