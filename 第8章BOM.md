### BOM

window 对象 BOM 的核心
控制窗口、框架和弹出窗口
利用 location 对象中的页面信息
使用 navigator 对象了解浏览器

ECMAScript 是 JavaScript 的核心，但如果要在 web 中使用 javaScript，那么 BOM（浏览器对象模型）则无疑才是真正的核心。BOM 提供了很多对象，用于访问浏览器的功能，这些功能与任何网页内容无关。多年来，缺少事实上的规范导致 BOM 既有意思又有问题，因为浏览器提供商会按照各自的想法随意去扩展它。于是，浏览器之间共有的对象就成为了事实上的标准。这些对象在浏览器中得以存在，很大程度上是由于它们提供了与浏览器的互操作性。W3C 为了把浏览器中 JavaScript 最基本的部分标准化，已经将 BOM 的主要方法纳入了 HTML5 的规范中。

#### windom 对象

BOM 的核心对象是 window，它表示浏览器的一个实例。在浏览器中，window 对象拥有双重角色，它既是通过 javaScript 访问浏览器窗口的一个接口，又是 ECMAScript 规定的 Global 对象。 这意味着在网页中定义的任何一个对象、变量和函数，都以 window 作为其 Global 对象，因此有权访问 parseInt()等方法

##### 全局作用域

由于 window 对象同时扮演着 ECMAScript 中 Global 对象的角色，因此所有在全局作用域中声明的变量函数都会变成 window 对象的属性和方法。

定义全局变量与在 window 对象上直接定义属性还有有一点差别：全局对象不能通过 delete 操作符删除，而直接定义在 window 对象上定义的属性可以

##### 窗口关系及框架

如果页面中包含框架，则每个框架都拥有自己的 window 对象，并且保存在 frames 集合中。在 frames 集合中，可以通过数组索引(从 0 开始，从左至右，从上至下)或者框架名称来访问相应的 window 对象。每个 window 对象都有一个 name 属性，其中包含框架的名称。

tips: 在使用框架的情况下，浏览器会存在多个 Global 对象。在每个框架中定义的全局变量会自动成为框架中 window 对象的属性。由于每个 window 对象都包含原生类型的构造函数，因此每个框架都有一套自己的构造函数，这些构造函数一一对应，但并不相等。例如，top.Object 并不等于 top.frames[0].Object.这个问题会影响到对跨框架传递的对象使用 instanceof 操作符

##### 窗口位置

用来确定和修改 window 对象位置和属性的方法有很多。 IE、Safari、Opera 和 Chrome 都提供了 screenLeft 和 screenTop 属性，分别用于表示窗口相对于屏幕左边和上边的位置。Firefox 则再 screenX 和 screenY 属性中提供相同的窗口位置信息，Safari 和 Chorme 也同时支持这两个属性。Opera 虽然也支持 screenX 和 screenY 属性，但与 screenLeft 和 screenTop 属性并不对应，因此建议大家不要在 opera 中使用
跨浏览器获取窗口左边上边位置例子
var leftPos = (typeof window.screenLeft === "number")? window.screenLeft:window.screenX;

##### 窗口大小
跨浏览器确定一个窗口的大小不是一件简单的事。 IE9+、Firefox、Safari、Opera和Chorme均为此提供了四个属性：innerWidth、innerHeight、outerWidth、outerHeight。在IE9+、Safari和Firefox中，outerWidth和outerHeight返回浏览器窗口本身的尺寸（无论是从最外层的window对象还是从某个框架访问）. 在Opera中，这两个属性的值表示页面视图容器的大小。而innerWidth和innerHeight则表示该容器中页面视图区的大小(减去边框宽度)

IE8及更早版本没有提供取得当前浏览器窗口尺寸的属性；不过，它通过DOM提供了页面可见区域的相关信息。
在IE、Firefox、Safari、Opera和Chorme中，document.documentElement.clientWidth和document.documentElement.clientHeight中保存了页面视口的信息。在IE6中，这些属性必须在标准模式下才有效；如果是混杂模式，就必须通过document.body.clientWidth和document.body.clinetHeight取得相同信息。而对于混杂模式下的Chorme,无论通过document.documentElement还是document.body中的clientWidth和clientHeight属性，都可以取得视口的大小。
虽然最终无法确定浏览区窗口本身的大小，但却可以取得页面视口的大小。
