# vue

### vuex 模块引入方式
https://www.cnblogs.com/chao202426/p/11481257.html

### utils文件夹 作用
存放自己封装的工具类函数，是一个共享的方法。

### v-loading 指令

### @click.left  @click.right

自定义指令 给dom 操作指令
解决 点击自菜单范围外 空白区 收起菜单
解决 图片加载优化 在未加载前用 背景色填充


### keep-alive
<keep-alive>
    <component :is="组件名称"></component>
</keep-alive>

使用keep-alive 组件不会再次init 初始化 也不会走生命周期
keep-alive 有两个属性 
activated 组件被唤醒时候的 再次渲染时候触发
deactived 包含组件销毁时候触发


选择性缓存  include包含  exclude排除组件

配合router 的meta 元信息中提供的信息 keepalive 信息 决定该路由组件是否做缓存

### mixin混入使用
使用方法
注意点

异步请求 直接返回异步函数 不要返回值 undefined
 https://www.cnblogs.com/Ivy-s/p/10022636.html
 
###  vue中使用screenfull插件实现页面全屏
https://blog.csdn.net/qq_40323256/article/details/103003430

### 解决element ui表格左右拖动 表头与内容对应不上
 .el-table th.gutter{
    display: table-cell!important;
 }
 ### element ui 
 表格合计自定义
 列宽度  头 体 合计 
 表头自定义渲染
 element ui上传一次后无法上传
 dialog 遗留  用v-if 重载  或者自带的生命周期节点
 el-table底部空白，el-table__body-wrapper is-scrolling-left元素高度计算错误 https://www.jianshu.com/p/efc413246efb
 表格 doLayout() 方法重渲染
 
 
