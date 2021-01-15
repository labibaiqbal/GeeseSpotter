

#include "geesespotter_lib.h"

char *createBoard(std::size_t xdim,std::size_t ydim){
	//Allocate a char array with xdim * ydim elements and initialize each element with zero.
	char *array{new char [ydim*xdim]};
	for(int i=0; i<xdim*ydim; i++){
			array[i]= 0;

		}

	return array;
}


void computeNeighbors(char*board,std::size_t xdim,std::size_t ydim){
	//For a board that contains only the values 0 or 9, compute the number of goose-neighbored fields.
	for(int i=0; i<ydim; i++){
		for(int j=0; j<xdim; j++){
			if(board[i*xdim+j]==9){
				for(int k=i-1; k<=i+1; k++){
					for(int l=j-1; l<=j+1; l++){
						if((l<xdim&&l>=0)&&(k<ydim&&k>=0)){
							if(board[k*xdim+l]!=9){
								board[k*xdim+l]++;
							}
						}
					}
				}
			}
		}
	}

	}









void hideBoard(char*board,std::size_t xdim,std::size_t ydim){
	//Hide all the field values.

	for (int i=0; i<ydim*xdim; i++){
			board[i]=board[i]| hiddenBit();

		}

	}




void cleanBoard(char*board){
	//To deallocate the given board.
	delete[] board;
	board=nullptr;

}


void printBoard(char*board,std::size_t xdim,std::size_t ydim){




	for (int i=0; i<ydim; i++){
			for(int k=0; k<xdim; k++){
				if(board[k+(i*xdim)]&markedBit()){
					std::cout<<'M';
				}else if(board[k+(i*xdim)]&hiddenBit()){
					std::cout<<'*';
				}else{
					std::cout<<(int)board[k+(i*xdim)];
				}
			}
			std::cout<<std::endl;

		}

}

int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){



	if(xloc==0&&yloc==0){
		if(board[xloc+(yloc*xdim)]&markedBit()){
			board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]^markedBit();
					return 1;
				}else if((board[xloc+(yloc*xdim)]&valueMask())==board[xloc+(yloc*xdim)]){
					return 2;
				}else{
					if((board[xloc+(yloc*xdim)]&valueMask())==0){
						for(int j=yloc; j<=yloc+1; j++){
							for(int k=xloc; k<=xloc+1; k++){

									if((board[k+(j*xdim)]&markedBit())==0){
										if((board[k+(j*xdim)]&valueMask())!=9)
											board[k+(j*xdim)]=board[k+(j*xdim)]&valueMask();
									}

							}
						}
							return 0;
					}else{
						if((board[xloc+(yloc*xdim)]&valueMask())== 9){
							board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
							return 9;
						}

						board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
						return 0;
					}
				}


	}else if(xloc==xdim-1&&yloc==0){

		if(board[xloc+(yloc*xdim)]&markedBit()){
			board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]^markedBit();
							return 1;
						}else if((board[xloc+(yloc*xdim)]&valueMask())==board[xloc+(yloc*xdim)]){
							return 2;
						}else{
							if((board[xloc+(yloc*xdim)]&valueMask())==0){
								for(int j=yloc; j<=yloc+1; j++){
									for(int k=xloc; k>=xloc-1; k--){

											if((board[k+(j*xdim)]&markedBit())==0){
												if((board[k+(j*xdim)]&valueMask())!=9)
													board[k+(j*xdim)]=board[k+(j*xdim)]&valueMask();
											}

									}
								}
									return 0;
							}else{
								if((board[xloc+(yloc*xdim)]&valueMask())== 9){
									board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
									return 9;
								}

								board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
								return 0;
							}
						}

		}else if(xloc==0&&yloc==ydim-1){

			if(board[xloc+(yloc*xdim)]&markedBit()){
				board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]^markedBit();
								return 1;
							}else if((board[xloc+(yloc*xdim)]&valueMask())==board[xloc+(yloc*xdim)]){
								return 2;
							}else{
								if((board[xloc+(yloc*xdim)]&valueMask())==0){
									for(int j=yloc; j>=yloc-1; j--){
										for(int k=xloc; k<=xloc+1; k++){

												if((board[k+(j*xdim)]&markedBit())==0){
													if((board[k+(j*xdim)]&valueMask())!=9)
														board[k+(j*xdim)]=board[k+(j*xdim)]&valueMask();
												}

										}
									}
										return 0;
								}else{
									if((board[xloc+(yloc*xdim)]&valueMask())== 9){
										board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
										return 9;
									}

									board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
									return 0;
								}
							}


		}else if(yloc==0&&(xloc>0&&xloc<xdim-1)){

			if(board[xloc+(yloc*xdim)]&markedBit()){
				board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]^markedBit();
				return 1;
			}else if((board[xloc+(yloc*xdim)]&valueMask())==board[xloc+(yloc*xdim)]){
				return 2;
			}else{
				if((board[xloc+(yloc*xdim)]&valueMask())==0){
					for(int j=yloc; j<=yloc+1; j++){
						for(int k=xloc-1; k<=xloc+1; k++){

								if((board[k+(j*xdim)]&markedBit())==0){
									if((board[k+(j*xdim)]&valueMask())!=9)
										board[k+(j*xdim)]=board[k+(j*xdim)]&valueMask();
								}

						}
					}
						return 0;
				}else{
					if((board[xloc+(yloc*xdim)]&valueMask())== 9){
						board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
						return 9;
					}

					board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
					return 0;
				}



		}

	}else if(xloc==0&&(yloc>0&&yloc<ydim-1)){

		if(board[xloc+(yloc*xdim)]&markedBit()){
			board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]^markedBit();
			return 1;
		}else if((board[xloc+(yloc*xdim)]&valueMask())==board[xloc+(yloc*xdim)]){
			return 2;
		}else{
			if((board[xloc+(yloc*xdim)]&valueMask())==0){
				for(int j=yloc-1; j<=yloc+1; j++){
					for(int k=xloc; k<=xloc+1; k++){

							if((board[k+(j*xdim)]&markedBit())==0){
								if((board[k+(j*xdim)]&valueMask())!=9)
									board[k+(j*xdim)]=board[k+(j*xdim)]&valueMask();
							}

					}
				}
					return 0;
			}else{
				if((board[xloc+(yloc*xdim)]&valueMask())== 9){
					board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
					return 9;
				}

				board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
				return 0;
			}



	}

}else if(xloc==xdim-1&&(yloc>0&&yloc<ydim-1)){

	if(board[xloc+(yloc*xdim)]&markedBit()){
		board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]^markedBit();
		return 1;
	}else if((board[xloc+(yloc*xdim)]&valueMask())==board[xloc+(yloc*xdim)]){
		return 2;
	}else{
		if((board[xloc+(yloc*xdim)]&valueMask())==0){
			for(int j=yloc-1; j<=yloc+1; j++){
				for(int k=xloc; k>=xloc-1; k--){

						if((board[k+(j*xdim)]&markedBit())==0){
							if((board[k+(j*xdim)]&valueMask())!=9)
								board[k+(j*xdim)]=board[k+(j*xdim)]&valueMask();
						}

				}
			}
				return 0;
		}else{
			if((board[xloc+(yloc*xdim)]&valueMask())== 9){
				board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
				return 9;
			}

			board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
			return 0;
		}



}

}else if(yloc==ydim-1&&(xloc>0&&xloc<xdim-1)){

	if(board[xloc+(yloc*xdim)]&markedBit()){
		board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]^markedBit();
		return 1;
	}else if((board[xloc+(yloc*xdim)]&valueMask())==board[xloc+(yloc*xdim)]){
		return 2;
	}else{
		if((board[xloc+(yloc*xdim)]&valueMask())==0){
			for(int j=yloc; j>=yloc-1; j--){
				for(int k=xloc-1; k<=xloc+1; k++){

						if((board[k+(j*xdim)]&markedBit())==0){
							if((board[k+(j*xdim)]&valueMask())!=9)
								board[k+(j*xdim)]=board[k+(j*xdim)]&valueMask();
						}

				}
			}
				return 0;
		}else{
			if((board[xloc+(yloc*xdim)]&valueMask())== 9){
				board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
				return 9;
			}

			board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
			return 0;
		}



}

}else if((yloc<ydim-1)&&(yloc>0)&&(xloc>0&&xloc<xdim-1)){

	if(board[xloc+(yloc*xdim)]&markedBit()){
		board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]^markedBit();
		return 1;
	}else if((board[xloc+(yloc*xdim)]&valueMask())==board[xloc+(yloc*xdim)]){
		return 2;
	}else{
		if((board[xloc+(yloc*xdim)]&valueMask())==0){
			for(int j=yloc-1; j<=yloc+1; j++){
				for(int k=xloc-1; k<=xloc+1; k++){

						if((board[k+(j*xdim)]&markedBit())==0){
							if((board[k+(j*xdim)]&valueMask())!=9)
								board[k+(j*xdim)]=board[k+(j*xdim)]&valueMask();
						}

				}
			}
				return 0;
		}else{
			if((board[xloc+(yloc*xdim)]&valueMask())== 9){
				board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
				return 9;
			}

			board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
			return 0;
		}



}



}else if(yloc==ydim-1&&xloc==xdim-1){

	if(board[xloc+(yloc*xdim)]&markedBit()){
		board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]^markedBit();
		return 1;
	}else if((board[xloc+(yloc*xdim)]&valueMask())==board[xloc+(yloc*xdim)]){
		return 2;
	}else{
		if((board[xloc+(yloc*xdim)]&valueMask())==0){
			for(int j=yloc; j>=yloc-1; j--){
				for(int k=xloc; k>=xloc-1; k--){

						if((board[k+(j*xdim)]&markedBit())==0){
							if((board[k+(j*xdim)]&valueMask())!=9)
								board[k+(j*xdim)]=board[k+(j*xdim)]&valueMask();
						}

				}
			}
				return 0;
		}else{
			if((board[xloc+(yloc*xdim)]&valueMask())== 9){
				board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
				return 9;
			}

			board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]&valueMask();
			return 0;
		}



}
}







	return 0;



}


int mark(char *board, std::size_t xdim,std::size_t ydim, std::size_t xloc, std::size_t yloc){

	if((board[xloc+(yloc*xdim)]&markedBit())==markedBit()){
						board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]^markedBit();
						return 0;
					}else if((board[xloc+(yloc*xdim)]&valueMask())==board[xloc+(yloc*xdim)]){
						return 2;
					}else{
						board[xloc+(yloc*xdim)]=board[xloc+(yloc*xdim)]|markedBit();
						return 0;
					}





			return 0;



	return 0;

}



bool isGameWon(char *board,std::size_t xdim,std::size_t ydim){

	int count_hiddengeese=0;
		int count_geese=0;
		int count_neighbourField=0;
		int count_revealedNeighbourField=0;
		for(int i=0; i<ydim; i++){
			for(int j=0; j<xdim; j++)
			if((board[(i*xdim)+j]&valueMask())==9){
				if(board[(i*xdim)+j]&hiddenBit()){
					count_hiddengeese++;

				}
				count_geese++;
			}else{
				if((board[(i*xdim)+j]&valueMask())==board[(i*xdim)+j]){
								count_revealedNeighbourField++;

				}
				count_neighbourField++;

			}

		}


		if(count_geese==count_hiddengeese){
			if(count_neighbourField==count_revealedNeighbourField){
				return true;
			}
		}else{
			return false;
		}



		return false;


}

