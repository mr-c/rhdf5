
H5PLprepend <- function(path) {
  res <- .Call("_H5PLprepend", path, PACKAGE = 'rhdf5')
  invisible(res)
}


H5PLsize <- function() {
  size <- .Call("_H5PLsize", PACKAGE = 'rhdf5')
  return(size)
}