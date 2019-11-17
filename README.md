# ft_printf

This is my implementation of console output function, which is known as printf in many programming languages. In this case it's C. The function returns number of printed characters.

The function completely mimics printf's behavior with such conversions as c, s, d, i, u, o, x, X, p, %%. f implemented partially (work in progress).

Included:

Management of h, hh, l, ll, j and z length conversions.

Management of #, 0, -, + and space flags.

Management of minimum field-width.

Management of presicion.

Management of * flag for presicion.

Specifier 'b' added to output argument as binary.
