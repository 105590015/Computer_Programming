#include <stdio.h>
typedef struct _Rectangle {
  int (*perimeter)();
  int length;
  int width;
} Rectangle;
typedef struct _Circle {
  int (*perimeter)();
  int radius;
} Circle;
typedef struct _Triangle {
  int (*perimeter)();
  int s1;
  int s2;
  int s3;
} Triangle;
int RectanglePerimeter(Rectangle *obj) { return (obj->length+obj->width)*2; }
int CirclePerimeter(Circle *obj) { return 8*obj->radius; }
int TrianglePerimeter(Triangle *obj) { return obj->s1+obj->s2+obj->s3; }
main() {
  int i,j=0,n,s1,s2,s3,sum=0,all[10]={0};
  char shape,nextline;
  Rectangle r;
  Circle c;
  Triangle t;
  scanf("%d%c",&n,&nextline);
  for(i=0;i<n;i++)
  {
      scanf("%c",&shape);
      if(shape=='C')
      {
          scanf("%d%c",&s1,&nextline);
          c.radius=s1;
          c.perimeter=CirclePerimeter;
          all[j++]=c.perimeter(&c);
      }
      else if(shape=='R')
      {
          scanf("%d %d%c",&s1,&s2,&nextline);
          r.length=s1;
          r.width=s2;
          r.perimeter=RectanglePerimeter;
          all[j++]=r.perimeter(&r);
      }
      else if(shape=='S')
      {
          scanf("%d%c",&s1,&nextline);
          r.length=s1;
          r.width=s1;
          r.perimeter=RectanglePerimeter;
          all[j++]=r.perimeter(&r);
      }
      else if(shape=='T')
      {
          scanf("%d %d %d%c",&s1,&s2,&s3,&nextline);
          t.s1=s1;
          t.s2=s2;
          t.s3=s3;
          t.perimeter=TrianglePerimeter;
          all[j++]=t.perimeter(&t);
      }
  }
  for(i=0;i<10;i++)
  {
      if(all[i]!=0)
        printf("%d\n",all[i]);
      sum+=all[i];
  }
  printf("%d",sum);
}
