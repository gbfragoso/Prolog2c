expr --> termo,rexpr.
rexpr --> [&],expr,{write('&'),write(' ')}.
rexpr --> ['|'],expr,{write('|'),write(' ')}.
rexpr --> [].
termo --> fator,rtermo.
rtermo --> [:],termo,{write(':'),write(' ')}.
rtermo --> [-],termo,{write('-'),write(' ')}.
rtermo --> [].
fator --> [X],{integer(X)},{write(X),write(' ')}.
fator --> ['('],expr,[')'].

run(X) :- tell('expr.txt'),
(
	firstsolution(X),
	fail;
	told
).

firstsolution(X) :- (expr(X,[]) -> true;
				false).