#ifndef KENO_BET
#define KENO_BET

#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using number_type = unsigned short int ; // <! data type for a keno hit .
using cash_type = float ; // <! Defines the wage type in this application .
using set_of_numbers_type = std::vector <number_type>;

class KenoBet{
  private:
    set_of_numbers_type m_spots; //<! Player's bet
    cash_type m_wage; //<! Player's wage
    number_type m_rounds; //<! Game rounds
  public:
    //*! Create an empty bet
		KenoBet(void);

		//*! Class destructor
    //~KenoBet(void);

    /*  Adds a number to the spots only if the number is not already there .
    @param spot_ The number we wish to include in the bet .
    @return T if number chosen is successfully inserted ; F otherwise . */
    bool add_number(number_type spot_);

    /*! Sets the amount of money the player is betting .
    @param wage_ The wage .
    @return True if we have a wage above zero ; false otherwise . */
    bool set_wage(cash_type wage_);

    /*! Set the amount of rounds player is betting.
    @param qnt rounds . */
    void set_rounds(number_type rounds_);

    //! Resets a bet to an empty state .
    void reset(void);

    /*! Retrieves the player’s wage on this bet .
    @return The wage value . */
    cash_type get_wage(void) const;

    /*! Retrieves the number of rounds on this bet .
    @return Rounds value . */
    number_type get_rounds(void) const;

    /*! Returns to the current number of spots in the player ’s bet .
    @return Number of spots present in the bet . */
    size_t size(void) const;

    /*! Determine how many spots match the hits passed as argument .
    @param hits_ List of hits randomly chosen by the computer .
    @return An vector with the list of hits . */
    set_of_numbers_type get_hits(const set_of_numbers_type & hits_) const;

    /* ! Return a vector < spot_type > with the spots the player has picked so far .
    @return The vector < spot_type > with the player ’s spots picked so far . */
    set_of_numbers_type get_spots(void) const;

    cash_type get_payout(cash_type round_wage, const set_of_numbers_type & hits_);
  };

#endif
