#include <iostream>
#include <vector>
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int N, M;
vector< vector<int> > board;
vector< vector<bool> > marker;
int max4( int a, int b, int c, int d ) {
	return max( max( a, b ), max( c, d ) );
}

int partialMaxSum( int r, int c, int count ) {
	if(count == 1) {
		return board[ r ][ c ];
	} else {
		int lp = -INT32_MAX;
		int rp = -INT32_MAX;
		int up = -INT32_MAX;
		int dp = -INT32_MAX;

		if( c > 0 && !marker[ r ][ c - 1 ] ) {
			marker[ r ][ c - 1 ] = true;
			lp = board[ r ][ c ] + partialMaxSum( r, c - 1, count - 1 );
			marker[ r ][ c - 1 ] = false;
		}
		if( c < M - 1 && !marker[ r ][ c + 1 ] ) {
			marker[ r ][ c + 1 ] = true;
			rp = board[ r ][ c ] + partialMaxSum( r, c + 1, count - 1 );
			marker[ r ][ c + 1 ] = false;
		}
		if( r > 0 && !marker[ r - 1 ][ c ] ) {
			marker[ r - 1 ][ c ] = true;
			up = board[ r ][ c ] + partialMaxSum( r - 1, c, count - 1 );
			marker[ r - 1 ][ c ] = false;
		}
		if( r < N - 1 && !marker[ r + 1 ][ c ] ) {
			marker[ r + 1 ][ c ] = true;
			dp = board[ r ][ c ] + partialMaxSum( r + 1, c, count - 1 );
			marker[ r + 1 ][ c ] = false;
		}

		return max4( lp, rp, up, dp );
	}
}

int checkSum( int r, int c ) {
	marker[ r ][ c ] = true;
	int res = partialMaxSum( r, c, 4 );
	marker[ r ][ c ] = false;
	return res;
}

int checkT( int r, int c ) {
	int lt = -INT32_MAX;
	int rt = -INT32_MAX;
	int ut = -INT32_MAX;
	int dt = -INT32_MAX;

	if( ( r > 0 && r < N - 1 ) && c > 0) { // lt
		lt = board[ r ][ c ] + board[ r - 1 ][ c ] + board[ r + 1 ][ c ] + board[ r ][ c - 1 ];
	}

	if( ( r > 0 && r < N - 1 ) && c < M - 1 ) {
		rt = board[ r ][ c ] + board[ r - 1 ][ c ] + board[ r + 1 ][ c ] + board[ r ][ c + 1 ];
	}

	if( r > 0 && ( c > 0 && c < M - 1 ) ) { // ut
		ut = board[ r ][ c ] + board[ r - 1 ][ c ] + board[ r ][ c - 1 ] + board[ r ][ c + 1 ];
	}

	if( r < N - 1 && ( c > 0 && c < M - 1 ) ) { // dt
		dt = board[ r ][ c ] + board[ r + 1 ][ c ] + board[ r ][ c - 1 ] + board[ r ][ c + 1 ];
	}

	return max4( lt, rt, ut, dt );
}

int main(){
    // for fast io 
    fastio;
	int i, j;
	cin >> N >> M;

	for( i = 0; i < N; i++ ) {
		board.push_back(vector<int>(M));
		for( j = 0; j < M ; j++ ) {
			cin >> board[ i ][ j ];		
		}
	}

	marker = vector< vector<bool> >( N, vector<bool>(M, false) );
	
	int maxSum = 0;
	for( i = 0; i < N; i++ ) {
		for( j = 0; j < M; j++ ) {
			int temp = checkSum( i, j );
			int temp2 = checkT( i, j );
			if( temp > maxSum ) {
				maxSum = temp;
			}

			if( temp2 > maxSum ) {
				maxSum = temp2;
			}
		}
	}

	cout << maxSum;
}