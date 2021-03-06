#include <cstdio>
#include <cstring>
using namespace std;

struct hugeint{
	int a[510];
	int len;
	bool zhen;
}a,b;
char x[510],y[510];

hugeint jf(hugeint a,hugeint b){
	hugeint ans;
	memset(ans.a,0,sizeof(ans.a));
	ans.len=0;
	if(a.len>b.len) ans.len=a.len;
	else ans.len=b.len;
	for(int i=0;i<ans.len;i++){
		ans.a[i]=a.a[i]+b.a[i]+ans.a[i];
		if(ans.a[i]>=10) {
			ans.a[i+1]+=ans.a[i]/10;
			ans.a[i]%=10;
		}
	}
	if(ans.a[ans.len]>0) ans.len++;
	return ans;
}

bool bj(hugeint a,hugeint b){
	if(a.len<b.len) return false;
	if(a.len>b.len) return true;
	int len=a.len;
	for(int i=len-1;i>=0;i--){
		if(a.a[i]<b.a[i]) return false;
	}
	return true;
}

int main(){
	scanf("%s",x);
	scanf("%s",y);
	if(x[0]!='-') a.zhen=true;
	if(y[0]!='-') b.zhen=true;
	a.len=strlen(x);
	b.len=strlen(y);
	for(int i=0;i<a.len;++i){
		a.a[i]=x[a.len-1-i]-'0';
	}
	for(int i=0;i<b.len;++i){
		b.a[i]=y[b.len-1-i]-'0';
	}
	hugeint ans=jf(a,b);
	for(int i=ans.len-1;i>=0;i--) printf("%d",ans.a[i]);

}
