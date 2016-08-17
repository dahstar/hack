

#include <stdlib.h>

#include <stdio.h>

#include <time.h>

#include <string.h> //Needed for strcat()

#include <ctype.h>


#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
 
#include <cassert>
#include <limits>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define each(it,o) for(auto it= (o).begin(); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define inrep int t;cin>>t; while(t--)
using namespace std;
 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii > vpii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll > vpll;
typedef vector<string> vs;
typedef long double ld;
 
template<typename T> ostream& operator<< ( ostream &o,vector<T> v ) {
    if ( v.size() >0 )
        o<<v[0];
    for ( unsigned   i=1; i<v.size(); i++ )
        o<<" "<<v[i];
    return o<<endl;
}
template<typename U,typename V> ostream& operator<< ( ostream &o,pair<U,V> p ) {
    return o<<"("<<p.first<<", "<<p.second<<") ";
}
template<typename T> istream& operator>> ( istream &in,vector<T> &v ) {
 
    for ( unsigned   i=0; i<v.size(); i++ )
        in>>v[i];
    return in;
}
template<typename T> T sqr ( T x ) {
    return x*x;
}
const double EPS=1.e-6;
bool aprEq ( double a, double b ) {
 
    double del= abs ( a-b );
//     cout<<"difference: "<<del<<endl;
    return del<EPS;
}
 
struct Point {
    int x,  y;
    Point ( int _x=0, int _y=0 ) : x ( _x ),y ( _y ) {}
    Point ( const pair<int,int> &p ) :Point ( p.first,p.second ) {}
    bool operator< ( const Point &o ) const {
        if ( o.x==x ) return y<o.y;
        return x<o.x;
    }
    bool operator== ( const Point &p ) const {
        return x==p.x &&y==p.y;
    }
    Point operator- ( const Point &o ) const {
        return Point ( x-o.x,y-o.y );
    }
    Point operator+ ( const Point &o ) const {
        return Point ( x+o.x,y+o.y );
    }
 
    ll normSqr() const {
        return  sqr ( ( ll ) x ) +sqr ( ( ll ) y );
    }
    double norm() const {
        return sqrt ( double ( x ) *double ( x ) +double ( y ) *double ( y ) );
 
    }
    void normalize() {
        double n=norm();
        if ( !n ) return;
        x/=n;
        y/=n;
    }
    Point ortho() {
        return Point ( y,-x );
 
    }
};
 
ostream & operator<< ( ostream &os, const Point &p ) {
    return os<<mp ( p.x,p.y );
 
}
 
ll cross ( const Point &a, const Point&b ) {
    return ( ll ) a.x*b.y- ( ll ) a.y*b.x;
}
 
bool collinear ( const Point &a, const Point &b, const Point&c ) {
    return !cross ( a-b,a-c ) ;
 
 
}
bool ccw ( const Point &a, const Point&b, const Point &c ) {
    return cross ( a-b,a-c ) >0;
}
 
vector<Point> hull(vector<Point> &p) {
    int sz = (int)p.size();
    if (sz < 2) return p;
    sort(all(p));
    p.resize(unique(all(p))-p.begin());
    int cnt = 0;
    vector<Point> h(sz * 2);
    for (int i = 0; i < sz; h[cnt++] = p[i++]) {
        while (cnt > 1 && !ccw(h[cnt - 2], h[cnt - 1], p[i])) {
            --cnt;
        }
    }
    for (int i = sz - 2, t = cnt; i >= 0; h[cnt++] = p[i--]) {
        while (cnt > t && !ccw(h[cnt - 2], h[cnt - 1], p[i])) {
            --cnt;
        }
    }
    --cnt;
    if (cnt == 2 && h[0] == h[1]) --cnt;
    h.resize(cnt);
    return h;
}
 
 
 
 
 
ll twoArea(const vector<Point>& points) {
    if ( points.size() <3 ) return 0;
    ll res=0;
    rep ( i,points.size()-1 ) {
        res+=cross(points[i],points[i+1]);
    }
    res+=cross (points.back(),points[0]);
    return abs(res);
}
 
int main() {
    ios_base::sync_with_stdio ( false );
    vll res;
    inrep {
        int n;
        cin>>n;
        vi a ( n );
        cin>>a;
 
        if ( n<=2 ) {
            res.push_back(0);
            continue;
        }
        int mi=a[0],ma=a[0];
        vector<Point> points;
        reu(i,1,n) {
            points.push_back(Point(mi,a[i]));
            if(ma>mi)points.push_back(Point(ma,a[i]));
            ma=max(ma,a[i]);
            mi=min(mi,a[i]);
        }
 
        vector<Point> conv=hull(points);
        res.push_back ( twoArea(conv) );
 
    }
    for ( ll x:res ) cout<<x<<'\n';
}
 
