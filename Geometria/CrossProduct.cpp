ll CrossProduct(ll x1 , ll y1 , ll x2, ll y2){
	return (x1 * y2) - (y1 * x2);
}

ll p = CrossProduct(    
                            x3 - x1,
                            y3 - y1,
                            x3 - x2,
                            y3 - y2
                        );
// check if P3 is in the left(-) or rigth(+)
