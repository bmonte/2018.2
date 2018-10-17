#include "../include/kenoBet.h"
#include "../include/functions.h"

const int spots_bet = 15;
const int hits = 16;

double PayoutTable[spots_bet][hits] = {
   { 0, 3 }, //1
   { 0, 1, 9}, //2
   { 0, 1, 2, 16 }, //3
   { 0, 0.5, 2, 6, 12}, //4
   { 0, 0.5, 1, 3, 15, 50}, //5
   { 0, 0.5, 1, 2, 3, 30, 75}, //6
   { 0, 0.5, 0.5, 1, 6, 12, 36, 100}, //7
   { 0, 0.5, 0.5, 1, 3, 6, 19, 90, 720}, //8
   { 0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200}, //9
   { 0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800}, //10
   { 0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000}, //11
   { 0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000}, //12
   { 0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000}, //13
   { 0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500}, //14
   { 0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000} //15
};

KenoBet::KenoBet(){
  m_wage = 0;
  m_spots.clear();
  m_rounds = 0;
}

bool KenoBet::add_number(number_type spot_){
    if (std::binary_search (m_spots.begin(), m_spots.end(), spot_) or spot_ > 80)
       return false; else m_spots.push_back (spot_);
    my::sort (m_spots);

return true;
}

bool KenoBet::set_wage(cash_type wage_){
  if (wage_ < 0)
     return false; else m_wage = wage_;

return true;
}

void KenoBet::set_rounds(number_type rounds_){
  m_rounds = rounds_;
}

void KenoBet::reset(void) {
  m_spots.clear();
  m_wage = 0;
}

cash_type KenoBet::get_wage(void) const {
  return m_wage;
}

number_type KenoBet::get_rounds(void) const {
  return m_rounds;
}

size_t KenoBet::size(void) const{
  return m_spots.size();
}

set_of_numbers_type KenoBet::get_hits(const set_of_numbers_type & hits_) const{
 set_of_numbers_type m_hits;
 for (unsigned int i = 0; i < size(); i++) {
   for (auto j = 0; j < 20; j++) {
     if (m_spots[i] == hits_[j]) {
       m_hits.push_back(m_spots[i]);
     }
   }
 }
 return m_hits;
}

set_of_numbers_type KenoBet::get_spots(void) const{
  return m_spots;
}
