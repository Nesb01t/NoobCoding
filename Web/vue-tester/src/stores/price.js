import { ref } from "vue";
import { defineStore } from "pinia";

export const usePriceStore = defineStore("userPrice", () => {
  const githubPrice = ref(0);
  const giteePrice = ref(0);

  function setPrice(type = "GitHub", newPrice) {
    type == "GitHub" ? (githubPrice = newPrice) : (giteePrice = newPrice);
  }
  function addPrice(type = "GitHub") {
    type == "GitHub" ? githubPrice++ : giteePrice++;
  }

  return { githubPrice, giteePrice, setPrice, addPrice };
});
