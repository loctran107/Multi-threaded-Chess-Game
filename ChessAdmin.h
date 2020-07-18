#ifndef _CHESSADMIN_H_
#define _CHESSADMIN_H_

#include "Chess.h"
//Definining namespace for Chess Admin
namespace chess_admin {

	class ChessAdmin {
		public:
			ChessAdmin() {}; //empty-argument constructor
			~ChessAdmin(); //destructor to clean up
			void playerMode() const; //To be implemented later
			void computerMode() const; 
			
	}; //ChessAdmin class


} //chess_admin namespace

#endif //_CHESSADMIN_H_
