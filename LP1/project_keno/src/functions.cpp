#include "../include/functions.h"

void my::sort(set_of_numbers_type & vector) {
  for (unsigned int x = 0; x < vector.size() - 1; x++){
    for (unsigned int y = 0; y < vector.size() - x - 1; y++){
        if (vector[y] > vector[y+1])
           std::swap(vector[y], vector[y+1]);
         }
    }
}

set_of_numbers_type set_random(void){
  srand(time(NULL)); //Seed

  set_of_numbers_type random;

  auto cont(0);
  while (cont < 20) {
    auto number = (rand() %80) + 1;

    if (!std::binary_search (random.begin(), random.end(), number)){
      random.push_back(number);
      cont++;
    }
    my::sort(random);
  }
  return random;
  /*set_of_numbers_type random;

  auto cont(0);
  while (cont < 20) {
    // Seed with a real random value, if available
    std::random_device seed;

    // Choose a random mean between 1 and 80
    std::default_random_engine rad(seed());
    std::uniform_int_distribution<int> uniform_dist(1, 80);
    int number = uniform_dist(rad);

    if (!std::binary_search (random.begin(), random.end(), number)){
      random.push_back(number);
      cont++;
    }
    std::sort (random.begin(), random.end());*/
  }

void my::file_reader(std::string file_path, KenoBet &object){
    std::ifstream bet_file;
    std::string line;
    auto iterator = 0;

    bet_file.open(file_path);
    if (!(bet_file.good() or bet_file.is_open())){
      std::cout << "ERROR: Aborting operation. . . " << std::endl;
      exit(-1);
    }
    getline(bet_file, line);
    object.set_wage(stof(line));

    getline(bet_file, line);
    object.set_rounds(stoul(line));

	  getline(bet_file, line);
    std::stringstream tmp_str(line);
    for (std::string num; tmp_str >> num; ) {
      if (iterator >= 15) break;
        if(object.add_number(stoi(num)))
          iterator++;
    }
}
