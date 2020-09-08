*安装   npm install -g electron
*创建项目   通过git克隆
	cd到项目
	执行命令
	克隆示例项目的仓库    git clone https://github.com/electron/electron-quick-start
	进入这个仓库   cd electron-quick-start
	安装依赖并运行   npm install && npm start
	运行  npm start
*用electron-forge创建一个项目
	npm install -g electron-forge
	electron-forge init my-project --template=vue
	cd my-project 
	npm start
	
	//打包成一个目录到out目录下，注意这种打包一般用于调试，并不是用于分发
	npm run package

	//打出真正的分发包，放在out\make目录下
	npm run make

Mac安装electron 遇到权限问题 解决方案
sudo npm install -g electron --unsafe-perm=true --allow-root


### drag&drop的避免
通常我们用Chrome的时候，有个特性是比如你往Chrome里拖入一个pdf，它就会自动用内置的pdf阅读器打开。你往Chrome里拖入一张图片，它就会打开这张图片。由于我们的electron应用的BrowserWindow其实内部也是一个浏览器，所以这样的特性依然存在。而这也是很多人没有注意的地方。也就是当你开发完一个electron应用之后，往里拖入一张图片，一个pdf等等，如果不是一个可拖拽区域（比如PicGo的上传区），那么它就不应该打开这张图、这个pdf，而是将其排除在外。

所以我们将在全局监听drag和drop事件，当用户拖入一个文件但是又不是拖入可拖拽区域的时候，应该将其屏蔽掉。因为所有的页面都应该要有这样的特性，所以我写了一个vue的mixin：

export default {
  mounted () {
    this.disableDragEvent()
  },
  methods: {
    disableDragEvent () {
      window.addEventListener('dragenter', this.disableDrag, false)
      window.addEventListener('dragover', this.disableDrag)
      window.addEventListener('drop', this.disableDrag)
    },
    disableDrag (e) {
      const dropzone = document.getElementById('upload-area') // 这个是可拖拽的上传区
      if (dropzone === null || !dropzone.contains(e.target)) {
        e.preventDefault()
        e.dataTransfer.effectAllowed = 'none'
        e.dataTransfer.dropEffect = 'none'
      }
    }
  },
  beforeDestroy () {
    window.removeEventListener('dragenter', this.disableDrag, false)
    window.removeEventListener('dragover', this.disableDrag)
    window.removeEventListener('drop', this.disableDrag)
  }
}

全局引入这个mixin;

### 实现自己titlebar
https://blog.csdn.net/weixin_33795093/article/details/87975795

### 主进程与渲染进程的信息传递 通信
https://segmentfault.com/a/1190000022254999/

### 实现单个实例应用 限制只启动一个应用
https://blog.csdn.net/luoshabugui/article/details/80894455

### electron的两个路径相关变量 _dirname,_static 配置
_dirname 是webpack 自带变量，表示当前js所在目录，一般是指主进程 main.js所在目录,对于主进程main.js来讲，就是当前项目目录
	在生成环境中__dirname是指向asar的绝对地址/dist/electron/，而__static是指向asar的绝对地址/dist/electron/static/。但是在生产和开发环境中__static都是可以更改的已达到自己使用目的。


_static  https://www.jianshu.com/p/7777ba4a7938
 一般在development  production

 ### electron-vue 实现后台多进程
 https://www.cnblogs.com/webbery/p/12751933.html
 https://www.cnblogs.com/webbery/p/12785108.html

 ### 监听窗口大小变化
https://blog.csdn.net/lbn2676043895/article/details/103563991

### mac 端窗口操作按钮的显示与隐藏 登录页只有关闭按钮 其他页面3个操作按钮
https://blog.csdn.net/jingjingchen1014/article/details/90518102




