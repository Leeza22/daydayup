## 在 jquery 中

### jQuery.extend(Object)

为 jquery 添加工具函数;用来在 jQuery 命名空间上增加新函数。扩展 jquery 对象本身；
例子
jQuery.extend({
min: function(a, b) { return a < b ? a : b; },
max: function(a, b) { return a > b ? a : b; }
});
jQuery.min(2,3)

### jQuery.fn.extend(object)

扩展 jQuery 集来提供新的方法(通常用来制作插件)
用来扩充 jQuery 对象
jQuery.fn.extend({
check: function() {
return this.each(function() { this.checked = true; });
},
uncheck: function() {
return this.each(function() { this.checked = false; });
}
});
\$("input[type=checkbox]").check()

作用于 jQuery 对象的方法

### jQuery.extend([deep], target, object1, [objectN])

用一个或多个其他对象来扩展一个对象，返回被扩展的对象。
如果不指定 target 给 jquery 命名空间本身进行扩展。有助于为 jQuery 增加新方法
如果第一个参数为 true,则 jQuery 返回一个深层次的副本，递归地复制找到的任何对象。否则的话，副本会和原对象共享结构。未定义的属性将不会被复制，然而从对象的原型继承的属性将会被复制。

## 在 js 中 javaScript 中 extends 关键字用来实现类的继承，原生构造函数的继承

## 在 vue 中 extend Vue.extend(options) 参数{object} options

用法：使用基础 Vue 构造器，创建一个"子类"。参数是一个包含 组件选项 的对象
data 选项是特例，在 Vue.extend()中它必须是函数
1、先创建组件构造器
2、创建 构造器实例 并挂在到一个元素上
传的 data 必须是 propsData 而不是 props
new Profile({
propsData:{
todo:[]
}
}).\$mount("#元素")

Vue.extend() 与 \$mount 结合
参考：https://www.jianshu.com/p/22c6a17f50a1
https://zhuanlan.zhihu.com/p/79056515
