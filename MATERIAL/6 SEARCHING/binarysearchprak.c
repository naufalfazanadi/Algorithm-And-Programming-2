#define FALSE 0
#define TRUE 1

void binary_search (int n, int arr[], int x_search) {
	int i, j, k;

	int bol = FALSE;

	i = 0;
	j = n-1;

	while((bol == 0) && (i<=j)){
		k = (i + j) / 2;
		if(arr[k] == x_search){
			bol = TRUE;
		}else if(arr[k] < x_search){
			i = k + 1;
		}else{
			j = k - 1;
		}
	}

	// output
	if(bol == TRUE){
		printf("ada pada tabel\n");
	}else{
		printf("tidak ditemukan\n");
	}

}