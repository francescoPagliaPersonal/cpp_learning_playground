#ifndef SCALARSTRUCT_H
# define SCALARSTRUCT_H

# include <string>

enum nbrStatus {
	OK,
	NODISP,
	NOPOSS,
	MAXERR
};

enum inType {
	CHAR,
	INTEGER,
	FLOAT,
	DOUBLE,
	NOTATYPE,
	MAXTYPE	
};

/* Input data stores: 
 * the validated std::string 
 * the datatype evaluated
 * the possiblitiy of being a litteral (inf/nan/etc)
 */
struct inData {
	std::string 	str;
	inType			type;
	int 			litteral; 
};

/* 
 */
struct scalars {
	char			nbrc;
	nbrStatus		nbrc_status;
	int 			nbri;
	nbrStatus		nbri_status;
	float 			nbrf;
	nbrStatus		nbrf_status;
	double 			nbrd;
	nbrStatus		nbrd_status;	
};



#endif