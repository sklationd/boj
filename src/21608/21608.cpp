#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <map>
#include <unordered_set>
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int N;
vector< vector<int> > classRoom;
vector< pair <int, unordered_set<int> > > prefer;
unordered_map< int, int > studentID2Index;

int getStudentCount( int studentID, int r, int c ) {
	int count = 0;
	int index = studentID2Index[ studentID ];

	if( r > 0 ) {
		if( prefer[ index ].second.find(classRoom[ r - 1 ][ c ] ) != prefer[ index ].second.end() ) {
			count++;
		}
	}

	if( c > 0 ) {
		if( prefer[ index ].second.find(classRoom[ r ][ c - 1 ] ) != prefer[ index ].second.end() ) {
			count++;
		}
	}

	if( r < N - 1 ) {
		if( prefer[ index ].second.find(classRoom[ r + 1 ][ c ] ) != prefer[ index ].second.end() ) {
			count++;
		}
	}
	
	if( c < N - 1 ) {
		if( prefer[ index ].second.find(classRoom[ r ][ c + 1] ) != prefer[ index ].second.end() ) {
			count++;
		}
	}

	return count;
}

int getPreferScore( int r, int c ) {
	int studentID = classRoom[r][c];
	int count = 0;
	int index = studentID2Index[ studentID ];

	if( r > 0 ) {
		if( prefer[ index ].second.find(classRoom[ r - 1 ][ c ] ) != prefer[ index ].second.end() ) {
			count++;
		}
	}

	if( c > 0 ) {
		if( prefer[ index ].second.find(classRoom[ r ][ c - 1 ] ) != prefer[ index ].second.end() ) {
			count++;
		}
	}

	if( r < N - 1 ) {
		if( prefer[ index ].second.find(classRoom[ r + 1 ][ c ] ) != prefer[ index ].second.end() ) {
			count++;
		}
	}
	
	if( c < N - 1 ) {
		if( prefer[ index ].second.find(classRoom[ r ][ c + 1] ) != prefer[ index ].second.end() ) {
			count++;
		}
	}

	if( count == 0 ) {
		return 0;
	} else {
		return pow( 10, count - 1 );
	}
}

int getEmptyCount( int r, int c ) {
	int count = 0;

	if( r > 0 ) {
		if( classRoom[ r - 1 ][ c ] == 0 ) {
			count++;
		}
	}

	if( c > 0 ) {
		if( classRoom[ r ][ c - 1 ] == 0 ) {
			count++;
		}
	}

	if( r < N - 1 ) {
		if( classRoom[ r + 1 ][ c ] == 0 ) {
			count++;
		}
	}
	
	if( c < N - 1 ) {
		if( classRoom[ r ][ c + 1 ] == 0 ) {
			count++;
		}
	}

	return count;
}

void locateStudent( int studentID ) {
	int studentCount[21][21] = {0,};
	int emptyCount[21][21] = {0,};

	int maxStudentCount = -1;
	int maxStudentDupCount = 0;
	int maxEmptyCount = -1;
	int maxEmptyDupCount = 0;

	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ ) {
			if( classRoom[i][j] == 0 ) { // if empty seat
				studentCount[i][j] = getStudentCount( studentID, i, j );

				if( maxStudentCount < studentCount[i][j] ) {
					maxStudentCount = studentCount[i][j];
					maxStudentDupCount = 0;
				}
				
				if( maxStudentCount == studentCount[i][j] ) {
					maxStudentDupCount++;
				}
			}
		}
	}

	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ ) {
			if( classRoom[i][j] == 0 && studentCount[i][j] == maxStudentCount ) { // if empty seat
				emptyCount[i][j] = getEmptyCount(i,j);

				if( maxEmptyCount < emptyCount[i][j] ) {
					maxEmptyCount = emptyCount[i][j];
					maxEmptyDupCount = 0;
				} 
				
				if( maxEmptyCount == emptyCount[i][j] ) {
					maxEmptyDupCount++;
				}
			}
		}
	}

	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ ) {
			if( classRoom[i][j] == 0 ) {
				if( maxStudentDupCount > 1 ) {
					if( maxEmptyDupCount > 1 ) {
						if( maxStudentCount == studentCount[i][j] && maxEmptyCount == emptyCount[i][j] ) {
							classRoom[i][j] = studentID;
							return;
						}
					} else {
						if( maxEmptyCount == emptyCount[i][j] ) {
							classRoom[i][j] = studentID;
							return;
						}
					}
				} else {
					if( maxStudentCount == studentCount[i][j] ) {
						classRoom[i][j] = studentID;
						return;
					}
				}
			}
		}
	}

}

int main(){
    // for fast io 
    fastio;

    int i,j;
    cin >> N;

	studentID2Index = unordered_map<int, int>();
	classRoom = vector< vector<int> >( N, vector<int>(N, 0));
	prefer = vector< pair< int, unordered_set<int> > >( N*N, make_pair( 0, unordered_set<int>() ) );

    for(i=0;i<N*N;i++){
		cin >> prefer[ i ].first;
		for(j=1;j<5;j++) {
			int temp;
			cin >> temp;
			prefer[ i ].second.insert( temp );
		}
		studentID2Index.insert( make_pair( prefer[ i ].first, i ) );
    }

	for(i=0;i<N*N;i++) {
		locateStudent( prefer[ i ].first );
	}

	int score = 0;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			score += getPreferScore(i,j);
		}
	}

	cout << score;

	return 0;
}
