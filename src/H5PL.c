#include "H5PL.h"
#include "H5pubconf.h"

////////////////////////////////////////////////////
// Dynamically-loaded Plugins (H5PL)
////////////////////////////////////////////////////

/* herr_t H5PLprepend	(	const char * 	search_path	)	 */
SEXP _H5PLprepend( SEXP _search_path ) {
  
  const char *search_path = CHAR(STRING_ELT(_search_path, 0));
  herr_t res;

  res = H5PLprepend(search_path);
    
  if(res < 0) {
    error("Unable to prepend value to plugin search path");
  }
  
  SEXP Rval = ScalarLogical(1);
  return Rval;
}

/* herr_t H5PLsize	(	unsigned int * 	num_paths	) */
SEXP _H5PLsize() {
  
  SEXP Rval;
  unsigned int nvals = 0;
  
  if(H5PLsize( &nvals ) < 0 ) {
    error("Unable to prepend value to plugin search path");
  }
  
  if(nvals <= INT32_MAX) {
    Rval = PROTECT(allocVector(INTSXP, 1));
    INTEGER(Rval)[0] = (int) nvals;
  } else {
    Rval = PROTECT(allocVector(REALSXP, 1));
    REAL(Rval)[0] = (double) nvals;
  }
  
  UNPROTECT(1);
  return Rval;
}

