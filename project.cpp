
#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <iostream>
#include <vector>
const size_t SCREEN_WIDTH = 70;
const size_t STRING_WIDTH = SCREEN_WIDTH - 4;

namespace funcTions {

	char* convert_size_t_to_string(const size_t* const value)
		 noexcept {
		 size_t copy{ *value }; size_t q = { 0 };
		char* string; if (copy != 0) {
			while (copy != 0) { copy /= 10; q++; }
			  string = (char*)malloc((q + 1)); assert(string != nullptr);
			 string[q] = '\0'; unsigned char uc{ 0 };
			  size_t temp; copy = *value;
			for (size_t i = q; i > 0; i--) {
				temp = copy % 10;
				 memcpy(&uc, &temp, sizeof(unsigned char));
				  string[i - 1] = uc + (int)'0';
				copy /= 10;
			}
		} else {
			string = (char*)malloc(2);
			 assert(string != NULL);
			   string[1] = '\0';
			  string[0] = '0';
		}
    return string;
	        }

	char** generate_array_of_strings_using(const std::vector<size_t>& array)
		  noexcept {
		char** arrayofstrings; const char c = ' ';
		  size_t max_length = array[0];
		  for (const auto& element : array) {
			  if (element > max_length) max_length = element;
		  } 
		  char* sTring; sTring = convert_size_t_to_string(&max_length);
		   max_length = strlen(sTring) + 1; // digit 1 to be deleted in case
		                                    // somebody needs to get rid of
											// the first gap in each string
		   // just for the sake of our specific programm
		          //max_length = 4;
		   // this line of code to be deleted in other projects
		   free(sTring);
	arrayofstrings = new char* [array.size()]; 
	   assert(arrayofstrings != nullptr);
		 for (size_t i = 0; i < array.size(); i++) {
			 arrayofstrings[i] = new char[max_length + 1];
			      assert(arrayofstrings[i] != nullptr);
				arrayofstrings[i][max_length] = '\0';
				memset(arrayofstrings[i], (int)c, max_length);
			sTring = convert_size_t_to_string(&array[i]);
 strncpy(&arrayofstrings[i][(max_length - strlen(sTring))], sTring, strlen(sTring));
		free(sTring);
		  }
		return arrayofstrings;
	}

	void find_min_and_max(const std::vector<double>* array,
		double& min, double& max) noexcept {
		   min = max = array->at(0);
		for (auto& element : *array) {
			if (element > max) max = element;
			else if (element < min) min = element;
		  }
		return;
	}

	template<typename T>
	T generateRandomDigitInRangeOf(const T lower_border,
		const T upper_border) noexcept {
   return ((((double)rand()) / RAND_MAX) * (upper_border - lower_border))
	   + lower_border;
	 }

}






int main() {
srand((unsigned int)time(NULL));


	  // Test example for functions
	/*const size_t a = 123456;
	 char* str = funcTions::convert_size_t_to_string(&a); 
	 printf("%s\n", str); free(str);
	std::vector<size_t> biins(10);
	for (size_t i = 0; i < 10; i++) {
		biins[i] = 23 * i + 90 * i;
	 }
	biins[5] = 12345;
	biins[3] = 130874;
	char** arr = funcTions::generate_array_of_strings_using(biins);
	std::cout << '\n';
	for (size_t i = 0; i < biins.size(); i++) {
		printf(":%s:\n", arr[i]);
	} 
	for (size_t i = 0; i < biins.size(); i++) {
		delete[] arr[i];
	} delete[] arr;*/


	size_t numbers_count{ 500 }, bins_count { 30 };
	   std::vector<size_t> bins;
	 std::vector<double> numbers;
	  //std::cerr << "Enter number of values to be processed:" << "\n";
	// std::cin >> numbers_count;
	   numbers.resize(numbers_count);
	   for (size_t i = 0; i < numbers_count; i++) {
	numbers[i] = funcTions::generateRandomDigitInRangeOf<double>(1.0, 300.0);
		    //std::cin >> numbers[i];
		   //std::cout << numbers[i] << "\n";
	              }
	    //std::cerr << "Enter number of bins: " << "\n";
	   //std::cin >> bins_count; 
		bins.resize(bins_count);

		double min, max;
	   funcTions::find_min_and_max(&numbers, min, max);
	     double bin_size = (max - min) / bins_count; 
	   bool found;  
	   for (size_t i = 0; i < numbers_count; i++) {
		      found = false; 
		   for (size_t j = 0; (j < (bins_count - 1)) && (!found); j++) {
			      auto low = min + j * (bin_size);
			      auto high = min + (j + 1) * bin_size;
			   if ((low <= numbers[i]) && (numbers[i] < high)) {
				   bins[j]++; 
				  found = true;
				}
		      }
		   if (!found) { bins[bins_count - 1]++; }
		     }

char** array_of_strings = funcTions::generate_array_of_strings_using(bins);
size_t maxb = bins.at(0);
for (const auto& example : bins) {
	if (example > maxb) maxb = example;
}
for (size_t i = 0; i < bins.size(); i++) {
  bins[i] = static_cast<size_t>(STRING_WIDTH * (((double)bins[i]) / maxb));
}
     std::cout << "\n";
	
	 const size_t length = strlen(array_of_strings[0]) + 1 + STRING_WIDTH + 1;
	   char* string1 = (char*)malloc(length + 1);
	    assert(string1 != nullptr); string1[length] = '\0';
	 const char symbol = '-';
	   memset(string1, (int)symbol, strlen(string1));
	   std::cout << " " << "+" << string1 << "+" << "\n";
	           size_t j = 0;
      for (size_t i = 0; i < bins.size(); i++) {
	std::cout <<" |"<< array_of_strings[i] << "|";
		 for (j = 0; j < bins[i]; j++) {
			  std::cout << "|";
		   }
		    while(j++ < length - strlen(array_of_strings[0]) - 1)
		 std::cout << " ";
		 std::cout << "|" << "\n";
	   }
	std::cout << " " << "+" << string1 << "+" << "\n";
	 
	 
	 for (size_t i = 0; i < bins.size(); i++) {
		 delete[] array_of_strings[i]; }
	       delete[] array_of_strings;
		      free(string1);
			
	 

	return 0;
}

