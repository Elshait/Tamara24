class Array{
	public static void main(String args[]){
		//Содание одномерного массиваи вывод значений элементов на экран 
		int nums[] = new int[10];
		int i;
		for (i=0; i < 10; i++)
		       nums[i] = i;
		for(i=0; i < 10; i++)
			System.out.println("Элемент ["+ i +"]:" + nums[i]);
		 //
		 int nums2[] = {99, -50, -245, 311, -50, 18, 90, 84, -4, 2};
		
		int min, max;
       		min = max = nums2[0];
		for(i=0; i < 10; i++){
			if(nums2[i] < min) min = nums2[i];
			if(nums2[i] > max) max = nums2[i];
		}
		System.out.println("МИнимальное значение в массиве: " + min + "\nМаксимальное значние в массиве" +max);
		// Пузырьковая сортировка массива 
		int a, b, t;
		int size = 10;
		System.out.println("Массив до сортировки: ");
		for (i=0; i < size; i++)
			 System.out.println(" " +nums2[i]);
		System.out.println();

		for(a=1; a < size; a++)
			for(b=size-1; b >= a; b--){
				if(nums2[b-1] > nums2[b]){
					t = nums[b-1];
					nums2[b-1] = nums2[b];
					nums[b] = t;
				}
			}
		System.out.println("Массив после сортировки: ");
                for (i=0; i < size; i++)
                         System.out.println(" " +nums2[i]);
                System.out.println();

		
	} 
}
