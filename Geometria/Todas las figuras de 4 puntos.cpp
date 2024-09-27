struct Pt{
	ld x, y;
	int id;
	Pt(ld x=0, ld y=0): x(x), y(y) {}
	Pt operator + (const Pt &o) const{
		return {x + o.x, y + o.y}; // a + b
	}
	Pt operator - (const Pt &o) const{
		return {x - o.x, y - o.y}; // a - b
	}
	Pt operator * (ld t) const{
		return {x * t, y * t}; // a * t
	}
	Pt operator / (ld t) const{
		return {x / t, y / t }; // a / t
	}
	ld operator * (const Pt &o) const{
		return x * o.x + y * o.y; // Producto Escalar (a * a)
	}
	ld operator ^ (const Pt &o) const{
		return x * o.y - y * o.x; // Producto Vectorial (a ^ a)
	}
};

void solve(int ith){
	Pt a,b,c,d;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cin >> d.x >> d.y;
	Pt v1,v2,v3,v4;
	v1 = b - a; v2 = c - b; v3 = d - c; v4 = a - d;
	if( v1 * v2 == 0 && v2 * v3 == 0 && v3 * v4 == 0 && v4 * v1 == 0 ){
		if( v1 * v1 == v2 * v2 ){
			cout << "square" << nl;
		}else{
			cout << "rectangle" << nl;
		}
	}else
	if( v1 * v1 == v2 * v2 && v2 * v2 == v3 * v3 && v3 * v3 == v4 * v4 ){
		cout << "rhombus" << nl;
	}else
	if( (v1^v3) == 0 && (v2^v4) == 0 ){
		cout << "parallelogram" << nl;
	}else
	if( (v1^v3) == 0 || (v2^v4) == 0 ){
		cout << "trapezium" << nl;
	}else{
		if( (v1 * v1 == v2 * v2 && v3 * v3 == v4 * v4) || (v1 * v1 == v4 * v4 && v2 * v2 == v3 * v3) ){
			cout << "kite" << nl;
		}else{
			cout << "none" << nl;
		}
	}
}
