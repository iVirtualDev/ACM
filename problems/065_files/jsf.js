var problems=[], problem2=[];
(function(){
	var v=
"000~Sum of two integers~001~Max of Integers~002~Set intersection~003~Contest Table~004~Athletes~005~Random descending a tree~006~Three Squares~007~Space Zoo~008~Brackets~009~Fibonacci numbers~010~New Year congratulations ~011~Brackets II~012~Correct dictionary~013~Boxes~014~War-cry~015~One rectangle~016~Two rectangles~017~Arithmetica v1.3~018~What is the number?~019~Bridges~020~Island of straight roads ~021~Fraction~022~Regular expression I~023~Way among sticks~024~Arithmetica 1.0~025~The optimal path~026~Operations~027~Odd number~028~Circle Game~029~Storm in a Rectangle~030~Disclosing of parentheses~031~Minimal sum of distances~032~Star War (epizode <b>V</b>)~033~Triangles~034~Rain~035~Camelot~036~Two cubes~037~Maximum profit~038~Roots of polynom~039~Calculating XOR via AND~040~Murder of mister C~041~Rubik's Cube 2 &times; 2 &times; 2~042~LCS problem~043~Intervals~044~Frame paving~045~Picture segments~046~Best clustering~047~Self-describing sequence~048~Chess end-game~049~Minimizing number of steps~050~Two regular expressions~051~Strange Tower~052~Permutation complexity~053~Love cycle~054~Mine field~055~Trip abroad~056~Best segmentation~057~Hacker's attack~058~Alise and Basilio~059~CD~060~Defragmentation~061~Reconstructing permutation~062~Regular Expression II~063~Casket ~064~Max product~065~Queue for tickets~066~Counting figures~067~Good permutations~068~2x1-paving~069~Graph Coloring~070~Square root of permutation~071~Cables~072~Chess Cube~073~Enclosing point with polygon~074~Spheres intersection~075~Root of the equation~076~Bracket structure correction~077~Queens~078~Next word~079~Fence~080~Japanese Crossword~081~Swimming pool~082~Clusterization of binary words~083~SAT-2~084~Farthest points~085~Triangle approximation~086~Anti-factorial~087~Tautology~088~p-adic numbers~089~8-puzzle~090~Graph Planarity~091~15-Puzzle ~092~Stations~093~What is the number (Part II)?~094~Resistance PS-scheme~095~Directed PS-graphs~096~Undirected PS-graphs~097~Cutted rectangle~098~Upgrading to strongly connected graph~099~Resistance PS-scheme, II~100~Nim Game -- Who is the winner? ~101~Stone Game -- who is the winner?~102~Stone Game II -- who is the winner? ~103~Nim Game -- Give Away! ~104~Camomile Game -- who is the winner?~105~MRQ problem~106~K-harmonious Workgroup~107~Infix to postfix form~108~Grammar of a Great Machine (Correct words 1)~109~Half-planes I~110~Graph existance~111~Reduction to common denominator~112~��������~113~Plane partition.~114~Unique radix~115~The Landing~116~Hard life~117~Polynom modulo P.~118~Pancake-week~119~Universal parser of expression~120~Range Query~122~�������~123~LCA~126~Minimize parentheses
	for(var i=0; 2*i<v.length; i++){
		problems[i]=[v[2*i],v[2*i]+' - '+v[2*i+1]];
		problem2[i]=[v[2*i+1],v[2*i]+' - '+v[2*i+1]];
	}
})()