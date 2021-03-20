import java.util.Scanner;
public class ch2_10 {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		
		int x1, y1, r1; // 두 번째 원의 중심 좌표와 반지름의 길이를 저장할 변수
		int x2, y2, r2; // 두 번째 원의 중심 좌표와 반지름의 길이를 저장할 변수
		int DistanceOfPoint; // 중심과 중심 사이의 거리를 저장할 변수
		
		System.out.print("첫번째 원의 중심과 반지름 입력>>");
		x1 = scanner.nextInt();
		y1 = scanner.nextInt();
		r1 = scanner.nextInt();
		
		System.out.print("두번째 원의 중심과 반지름 입력>>");
		x2 = scanner.nextInt();
		y2 = scanner.nextInt();
		r2 = scanner.nextInt();
		
		DistanceOfPoint = (int)Math.sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
		
		  if(r1 + r2 > DistanceOfPoint) 
			System.out.println("두 원은 서로 겹친다.");
		else
			System.out.println("두 원은 서로 겹치치 않는다.");
		
		scanner.close();
	}

}
