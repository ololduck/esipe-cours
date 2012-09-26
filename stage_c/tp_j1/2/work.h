#ifndef work_h_
#define work_h_
/**
 * Main work force
 * @param to_trim string containing the list of chars to trim
 */
void work(char* to_trim);

/**
 * Checks the presence of the char c in the string s
 * @param  c the char to check
 * @param  s the string to check c in
 * @return   0 if not present, 1 if present
 */
int c_is_present(char c, char* s);

#endif
