Simple multithreaded read&write contains:
	-shared structure
	-read function, that output name of shared structure, reader thread id and writers id
	-write function, that put writer thread id into shared structure

Only one writer or N readers can use the same shared structure in the same time.
Read and write functions can be rewrited for some reasons.
