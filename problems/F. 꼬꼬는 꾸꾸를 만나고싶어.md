# E. 꼬꼬는 꾸꾸를 만나고싶어

| 시간 제한 | 메모리 제한 |
| --- | --- |
| 1초 | 256MB |

## 문제

아직도 졸업하지 못한 꼬꼬는 험난한 기말고사를 마치고 낙산공원에서 산책하며 쉬기로 결정했다. 꼬꼬는 마주오고 있는 꼬꼬의 연인인 꾸꾸를 발견하고서 신나서 폴짝폴짝 서로를 향해 점프하기 시작했다.

꼬꼬와 꾸꾸의 위치는 수직선상의 정수 좌표로 표현될 수 있고, 꼬꼬는 현재 $x$에, 꾸꾸는 $y$에 위치해 있다 $(x < y)$. 매 초마다 꼬꼬는 $a$만큼 양의 방향으로, 꾸꾸는 $b$만큼 음의 방향으로 점프한다.

예를 들어 $x=0, \space y=10, \space a=2, \space b=3$ 이라고 하면, 1초에 꼬꼬와 꾸꾸는 2와 7에 위치해 있을 것이고, 2초에는 모두 4에 위치해 있을 것이다.

꼬꼬는 높게 점프하고, 꾸꾸는 낮게 점프하기 때문에 공중에서는 만나지 않는다.

과연 꼬꼬와 꾸꾸가 같은 위치에 동시에 만날 수 있을까? 만날 수 있다면 얼마나 오래 걸릴까?

## 입력

각 테스트는 하나 이상의 테스트 케이스를 포함한다. 첫 번째 줄에는 테스트 케이스의 수 $t \space  (1 \leq t \leq 1000)$ 가 주어진다.

각 테스트 케이스는 한 줄로 구성되어 있다. 이 줄에는 네 개의 정수 $x, \space y, \space a, \space b \space (0 \leq x < y \leq 10^9, 1 \leq a, b \leq 10^9)$ 가 주어진다.

## 출력

각 테스트 케이스에 대해, 꼬꼬와 꾸꾸가 같은 위치에 있게 되는 데에 걸리는 시간(초)을 출력한다.

둘이 동시에 같은 위치에 있을 수 없다면, −1을 출력한다.

## 예제 입력

```
5
0 10 2 3
0 10 3 3
900000000 1000000000 1 9999999
1 2 1 1
1 3 1 1
```
## 예제 출력

```
2
-1
10
-1
1
```
