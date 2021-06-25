/**
 * 将import 组件转换成动态导入
 * eg.
 * import formContact from '../widgets/formContact/formContact.vue'
 * 变为：
 * formContact: () => import( '../widgets/formContact/formContact.vue')
 * @param {*} str // 字符串 最好用模版字符串
 * @returns newStr
 */
const transform = (str) => {
  // 匹配路径数组
  str += 'import'
  const patt_arr = /(import.*?)(?=\s*import)/g;
  const arr = str.match(patt_arr);

  // 遍历改造
  let newStr = '';
  for (let i=0; i<arr.length; i++) {
    const pattern = /import\s*(.*?)\s*from(.*)\s*/g;
    const res = pattern.exec(arr[i]);
    if (i === 0) newStr += `${res[1]}: () => import(${res[2]})`;
    else newStr += `,\n${res[1]}: () => import(${res[2]})`;
  }
  console.log(newStr)
  return newStr
}

transform(`import formDepartment from '../widgets/formDepartment/formDepartment.vue'
import formContact from '../widgets/formContact/formContact.vue'
import formLevel from '../widgets/formLevel/formLevel.vue'
import formPost from '../widgets/formPost/formPost.vue'
import formDate from '../widgets/formDate/formDate.vue'
import formInput from '../widgets/formInput/formInput.vue'
import formTextarea  from '../widgets/formTextarea/formTextarea.vue'
import formNumber from '../widgets/formNumber/formNumber.vue'
import formRadio from '../widgets/formRadio/formRadio.vue'
import formCheckbox from '../widgets/formCheckbox/formCheckbox.vue'
import formAmount from '../widgets/formAmount/formAmount.vue'
import formSelect from '../widgets/formSelect/formSelect.vue'
import formCascader from '../widgets/formCascader/formCascader.vue'
import formCalculatingtime from '../widgets/formCalculatingtime/formCalculatingtime.vue'
import formCalculator from '../widgets/formCalculator/formCalculator.vue'
import formDividingLine from '../widgets/formDividingLine/formDividingLine.vue'
import formPointer from '../widgets/formPointer/formPointer.vue'
import formImgupload from '../widgets/formImgupload/formImgupload.vue'
import formAnnex from '../widgets/formAnnex/formAnnex.vue'
import formRelatedapprovalform from '../widgets/formRelatedapprovalform/formRelatedapprovalform.vue'
import formDatasource from '../widgets/formDatasource/formDatasource.vue'
import formLink from '../widgets/formLink/formLink.vue'
import formHide from '../widgets/formHide/formHide.vue'
import formNote from '../widgets/formNote/formNote.vue'
import formSwitch from '../widgets/formSwitch/formSwitch.vue'`)