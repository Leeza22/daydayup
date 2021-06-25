export function download(src, fileName, fileType, isNotImage) {
  if (isNotImage) {
    // 判断是否为chrome里的图片
    fileLinkToStreamDownload(src, fileName, fileType)
  } else {
    ImgtodataURL(src, fileName, fileType)
  }
}

export function fileLinkToStreamDownload(url, fileName, type) {
  const xhr = new XMLHttpRequest()
  xhr.open('get', url, true)
  xhr.setRequestHeader('Content-type', `application/${type}`)
  xhr.responseType = 'blob'
  xhr.onload = function() {
    if (this.status === 200) {
      var blob = this.response
      downloadNormalFile(blob, fileName)
    }
  }
  xhr.send()
}

export function downloadNormalFile(blob, filename) {
  var eleLink = document.createElement('a')
  let href = blob
  if (typeof blob === 'string') {
    eleLink.target = '_blank'
  } else {
    href = window.URL.createObjectURL(blob) // 创建下载的链接
  }
  eleLink.href = href
  eleLink.download = filename // 下载后文件名
  eleLink.style.display = 'none'
  // 触发点击
  document.body.appendChild(eleLink)
  eleLink.click() // 点击下载
  // 下载完成移除元素
  document.body.removeChild(eleLink)
  if (typeof blob === 'string') {
    window.URL.revokeObjectURL(href) // 释放掉blob对象
  }
}

export function ImgtodataURL(url, filename, fileType) {
  getBase64(url, fileType, (_baseUrl) => {
    // 创建隐藏的可下载链接
    var eleLink = document.createElement('a')
    eleLink.download = filename
    eleLink.style.display = 'none'
    // 图片转base64地址
    eleLink.href = _baseUrl
    // 触发点击
    document.body.appendChild(eleLink)
    eleLink.click()
    // 然后移除
    document.body.removeChild(eleLink)
  })
}

export function getBase64(url, fileType, callback) {
  // 通过构造函数来创建的 img 实例，在赋予 src 值后就会立刻下载图片
  var Img = new Image()
  let dataURL = ''
  Img.src = url
  Img.setAttribute('crossOrigin', 'Anonymous')
  Img.onload = function() {
    // 要先确保图片完整获取到，这是个异步事件
    const canvas = document.createElement('canvas') // 创建canvas元素
    const width = Img.width // 确保canvas的尺寸和图片一样
    const height = Img.height
    canvas.width = width
    canvas.height = height
    canvas.getContext('2d').drawImage(Img, 0, 0, width, height) // 将图片绘制到canvas中
    dataURL = canvas.toDataURL('image/' + fileType) // 转换图片为dataURL
    callback ? callback(dataURL) : null
  }
}
